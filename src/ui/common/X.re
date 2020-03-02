open Lib;
open Revery;
open Revery.Math;
open Revery.UI;
open Revery.UI.Components;

let style =
  Style.[
    alignItems(`Stretch),
    flexDirection(`Row),
    flexGrow(1),
  ];

let make = (~children=React.empty, ()) => {
  <View style> children </View>;
};
