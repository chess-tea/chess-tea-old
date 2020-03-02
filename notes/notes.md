# Notes

## General

- Always `open Lib;` at the start of each file
- The entire application is a "library" according to dune so it can be tested
  - Entry point is `App.re`
  - The "executable" source is `AppExe.re` and only has 1 line calling `App.run()`
