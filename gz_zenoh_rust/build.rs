use std::fs;
use std::io::Result;
use std::path::Path;

extern crate prost_build;

const UNSUPPORTED_PROTOS:[&str; 4] =["any.proto", "parameter.proto", "param.proto", "parameter_value.proto"];

fn get_protos(dir: &Path, protos: &mut Vec<String>) -> Result<()> {
    for entry in fs::read_dir(dir)? {
        let entry = entry?;
        let path = entry.path();
        if path.is_dir() {
            get_protos(&path, protos)?;
        } else if path.is_file()
            && path.extension().and_then(|s| s.to_str()) == Some("proto")
            && let Some(path_str) = path.to_str()
            && let Some(file_name) = path.file_name()
            && !UNSUPPORTED_PROTOS.contains(&file_name.to_str().unwrap())
        {
            println!("{}", path_str);
            protos.push(path_str.to_string());
        }
    }
    Ok(())
}

fn main() -> Result<()> {
    let mut protos = Vec::new();
    // let proto_path = Path::new("/Users/addisuzt/ws/jetty/src/gz-msgs/proto");
    let proto_path = Path::new("src/proto");
    get_protos(proto_path, &mut protos)?;

    prost_build::compile_protos(&protos, &[proto_path.to_str().unwrap()])?;

    Ok(())
}

