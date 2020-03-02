open Lib;
open Revery;
open Revery.Math;
open Revery.UI;
open Revery.UI.Components;

module FillerCell = {
  let style = Style.[flexGrow(1)];

  let make = () => {
    <View style />;
  };
};

module FillerRow = {
  let style = Style.[flexGrow(1)];

  let make = () => {
    <View style />;
  };
};

module Cell = {
  let styleLight =
    Style.[
      backgroundColor(C.Color.text),
      alignItems(`Stretch),
      width(64),
      height(64),
    ];

  let styleDark =
    Style.[
      backgroundColor(C.Color.bgDarkWeak),
      alignItems(`Stretch),
      width(64),
      height(64),
    ];

  let textStyle =
    Style.[
      color(C.Color.accentRed),
      fontFamily(C.Font.firaCodeBold),
      fontSize(36.0),
    ];

  let make = (~dark, ~text="", ()) => {
    let style = dark ? styleDark : styleLight;
    <View style> <Text style=textStyle text /> </View>;
  };
};

module Row = {
  let style =
    Style.[
      backgroundColor(C.Color.accentOrange),
      alignItems(`Stretch),
      flexDirection(`Row),
    ];

  let make = (~children, ()) => {
    <View style> children </View>;
  };
};

module Board = {
  let style =
    Style.[
      backgroundColor(C.Color.accentOrange),
      alignItems(`Stretch),
      flexDirection(`Column),
      flexGrow(1),
    ];

  let make = (~children, ()) => {
    <View style> children </View>;
  };
};

let style =
  Style.[
    backgroundColor(C.Color.accentOrange),
    alignItems(`Stretch),
    flexDirection(`Row),
    flexGrow(1),
  ];

let make = () => {
  <View style>
    <Board>
      <FillerRow />
      <Row>
        <FillerCell />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <FillerCell />
      </Row>
      <Row>
        <FillerCell />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <FillerCell />
      </Row>
      <Row>
        <FillerCell />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <FillerCell />
      </Row>
      <Row>
        <FillerCell />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <FillerCell />
      </Row>
      <Row>
        <FillerCell />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <FillerCell />
      </Row>
      <Row>
        <FillerCell />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <FillerCell />
      </Row>
      <Row>
        <FillerCell />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <FillerCell />
      </Row>
      <Row>
        <FillerCell />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <Cell dark=true />
        <Cell dark=false />
        <FillerCell />
      </Row>
      <FillerRow />
    </Board>
  </View>;
};
