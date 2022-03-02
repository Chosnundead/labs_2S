import React from "react";
import { useState } from "react";
import "../styles/Chess.css";

const Chess = () => {
  let words = ["A", "B", "C", "D", "E", "F", "G", "H"];
  let numbers = [8, 7, 6, 5, 4, 3, 2, 1];
  let headOrFoot = words.map((one) => <td id="white">{one}</td>);
  headOrFoot = (
    <tr>
      <td id="white"></td>
      {headOrFoot}
      <td id="white"></td>
    </tr>
  );
  let mainOfTheChess = numbers.map((item) => {
    return (
      <tr>
        <td id="white">{item}</td>
        {numbers.map((step) => {
          return <td></td>;
        })}
        <td id="white">{item}</td>
      </tr>
    );
  });
  return (
    <table className="chess">
      <tbody>
        {headOrFoot}
        {mainOfTheChess}
        {headOrFoot}
      </tbody>
    </table>
  );
};

export default Chess;
