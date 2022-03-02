import React from "react";
import { useState } from "react";
import "../styles/TableOfStocks.css";

const SortTable = () => {
  const [table, setTable] = useState([
    {
      name: "Butter",
      price: 0.9,
      inStock: 99,
    },
    {
      name: "Cheese",
      price: 4.9,
      inStock: 20,
    },
    {
      name: "FFC",
      price: 99,
      inStock: 12,
    },
    {
      name: "Heavy Cream",
      price: 3.9,
      inStock: 9,
    },
    {
      name: "Milk",
      price: 1.9,
      inStock: 32,
    },
    {
      name: "Sour Cream",
      price: 2.9,
      inStock: 86,
    },
    {
      name: "Yoghurt",
      price: 2.4,
      inStock: 12,
    },
  ]);
  return (
    <table className="tableOfStocks">
      <thead>
        <tr>
          <th>Name</th>
          <th
            onClick={(event) => {
              let temp = table;
              temp.sort(function (a, b) {
                return a.price > b.price;
              });
              setTable(temp);
            }}
          >
            Price
          </th>
          <th>In Stock</th>
        </tr>
      </thead>
      <tbody>
        {table.map((one) => (
          <tr>
            <td>{one.name}</td>
            <td>{one.price}</td>
            <td>{one.inStock}</td>
          </tr>
        ))}
      </tbody>
    </table>
  );
};

export default SortTable;
