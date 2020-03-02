open Lib;

include GlobalState.Make({
  type action = Action.t;
  type state = State.t;
  let initialState = State.default;
  let reduce = Reducer.reduce;
  let equals = (==);
});
