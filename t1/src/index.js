import React from "react";
import ReactDOM from "react-dom";
import App from "./App";

ReactDOM.render(<App lab="1" />, document.getElementById("root"));
document.querySelector("#select").addEventListener("change", () => {
  switch (document.querySelector("#select").value) {
    case "1":
      ReactDOM.render(<App lab="1" />, document.getElementById("root"));
      break;
    case "2":
      ReactDOM.render(<App lab="2" />, document.getElementById("root"));
      break;
    case "3":
      ReactDOM.render(<App lab="3" />, document.getElementById("root"));
      break;
    case "4":
      ReactDOM.render(<App lab="4" />, document.getElementById("root"));
      break;
    case "5":
      ReactDOM.render(<App lab="5" />, document.getElementById("root"));
      break;
    case "6":
      ReactDOM.render(<App lab="6" />, document.getElementById("root"));
      break;
  }
});
