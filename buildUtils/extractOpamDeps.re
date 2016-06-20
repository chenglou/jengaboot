/* extracts `jengaboot.opamDependencies`, an object like the regular `dependencies` field */

open Yojson.Basic;

let packageJsonPath = Sys.argv.(1);

let deps =
  from_file packageJsonPath |>
    Util.member "jengaboot" |> Util.to_option (fun a => a |> Util.member "opamDependencies");

switch deps {
| Some (`Assoc d) => d |> List.map fst |> String.concat "\n" |> print_endline
| _ => ()
};

/* ocamlfind ocamlc -pp refmt -linkpkg -package yojson -g -impl extractOpamDeps.re -o extractOpamDeps.out 2>&1 | huh */