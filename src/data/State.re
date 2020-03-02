open Lib;

type t = {
  _extra: unit,
  nothing: unit,
};

let default = () => {_extra: (), nothing: ()};
