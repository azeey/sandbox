A quick demonstration of how SDFormat descriptions (schemas) 
can be extended. The example loads the `model_ext.sdf` file 
which adds the element `<test_param>` to `<model>`.

Notes

* libsdformat currently fails if the `default` value is not set in a 
  description file.
* `model_ext.sdf` has to start with `<element name="model"...>`. If instead, it 
  contained only `<element name="test_param"...>`, libsdformat seems to replace 
  the current description of model and use the description given in 
  `model_ext.sdf`. This means the `<model>` tag is now an unknown tag and 
  libsdformat emits the following warning:
  ```
  Warning [Utils.cc:130] 
  [/sdf/model[@name="test_model"]:/usr/local/google/home/addisuzt/code/sandbox/sdf_custom_schema/test_file.sdf:L2]: 
  XML Element[model], child of element[sdf], not defined in SDF. Copying[model] 
  as children of [sdf].
  ```
* Attributes and elements can only be added. Overriding elements or attributes 
  or removing them from the spec is not possible with this approach
* Adding elements to child elements, e.g. `<link>` doesn't seem to be possible 
  from `model_ext.sdf`. It'll need to be done by creating `link_ext.sdf` file 
  and modifying `loadExtension` to call `initFile` on the `<link>` description.

