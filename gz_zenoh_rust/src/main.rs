use prost::Message;
use uuid::Uuid;

pub mod gz {
    pub mod msgs {
        include!(concat!(env!("OUT_DIR"), "/gz.msgs.rs"));
    }
}

fn create_fqdn(partition: &str, topic: &str) -> String {
    format!("@/{}@/{}", partition, topic)
}

fn create_token(partition:&str, topic:&str, type_name: &str) -> String
{
    let session_id = Uuid::new_v4();
    let node_id = Uuid::new_v4();
    let entity_id = Uuid::new_v4();
    let entity_kind = "MS";

    let token = format!("@gz/%{}/{}/{}/{}/{}/%/%/%/%{}/{}/%/%", partition, session_id, node_id, entity_id, entity_kind, topic, type_name);
    token
}

#[tokio::main]
async fn main() {
    let session = zenoh::open(zenoh::Config::default()).await.unwrap();

    let partition = "zenoh";
    let topic = "foo";
    let type_name = "gz.msgs.StringMsg";

    let fully_qualified_topic = create_fqdn(partition, topic);

    let subscriber = session
        .declare_subscriber(fully_qualified_topic).await.unwrap();
    let _z_token = session.liveliness().declare_token(create_token(partition, topic, type_name)).await.unwrap();

    while let Ok(sample) = subscriber.recv_async().await {
        let payload = &*sample.payload().to_bytes();

        match gz::msgs::StringMsg::decode(payload) {
            Ok(message) => {
                println!("{}", message.data);
            }
            Err(e) => {
                eprintln!("Failed to deserialize Protobuf message: {}", e);
            }
        }
    };
}

