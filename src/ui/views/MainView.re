open Lib;
open Revery;
open Revery.Math;
open Revery.UI;
open Revery.UI.Components;

let textStyle =
  Style.[
    color(C.Color.text),
    fontFamily(C.Font.firaSansRegular),
    fontSize(16.0),
  ];

module ObjectBrowser = {
  let style =
    Style.[
      backgroundColor(C.Color.bgDark),
      width(220),
      padding(8),
      overflow(`Hidden),
    ];
  // borderRight(~color=C.Color.borderInverse, ~width=1),
  let make = () => {
    <View style> <Text style=textStyle text="Objects" /> </View>;
  };
};

module Workspace = {
  let style =
    Style.[
      backgroundColor(C.Color.bgDarkWeak),
      flexGrow(1),
      padding(8),
      overflow(`Hidden),
    ];
  let make = () => {
    <View style> <Text style=textStyle text="Workspace" /> </View>;
  };
};

let make = () => {
  <X> <ObjectBrowser /> <Workspace /> </X>;
};
