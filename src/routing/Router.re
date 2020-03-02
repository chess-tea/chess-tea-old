
type route =
  | Main
  | ChessBoard
  | Playground;

include Grout.Make({
  type t = route;
  let default = Main;
  let equals = (==);
});
