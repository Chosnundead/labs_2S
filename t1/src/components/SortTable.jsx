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
  const [vector, setVector] = useState([true, true, true]);
  let temp, sortData;
  return (
    <table className="tableOfStocks">
      <thead>
        <tr>
          <th
            onClick={(event) => {
              temp = table.concat();
              if (vector[2])
                sortData = temp.sort((a, b) => {
                  if (a["name"] < b["name"]) {
                    return -1;
                  }
                  if (a["name"] > b["name"]) {
                    return 1;
                  }
                  return 0;
                });
              else
                sortData = temp.sort((a, b) => {
                  if (a["name"] > b["name"]) {
                    return -1;
                  }
                  if (a["name"] < b["name"]) {
                    return 1;
                  }
                  return 0;
                });
              setVector([vector[0], vector[1], !vector[2]]);
              setTable(sortData);
            }}
          >
            Name
          </th>
          <th
            onClick={(event) => {
              temp = table.concat();
              if (vector[0])
                sortData = temp.sort((a, b) => {
                  if (a["price"] < b["price"]) {
                    return -1;
                  }
                  if (a["price"] > b["price"]) {
                    return 1;
                  }
                  return 0;
                });
              else
                sortData = temp.sort((a, b) => {
                  if (a["price"] > b["price"]) {
                    return -1;
                  }
                  if (a["price"] < b["price"]) {
                    return 1;
                  }
                  return 0;
                });
              setVector([!vector[0], vector[1], vector[2]]);
              setTable(sortData);
            }}
          >
            Price
          </th>
          <th
            onClick={(event) => {
              temp = table.concat();
              if (vector[1])
                sortData = temp.sort((a, b) => {
                  if (a["inStock"] < b["inStock"]) {
                    return -1;
                  }
                  if (a["inStock"] > b["inStock"]) {
                    return 1;
                  }
                  return 0;
                });
              else
                sortData = temp.sort((a, b) => {
                  if (a["inStock"] > b["inStock"]) {
                    return -1;
                  }
                  if (a["inStock"] < b["inStock"]) {
                    return 1;
                  }
                  return 0;
                });
              setVector([vector[0], !vector[1], vector[2]]);
              setTable(sortData);
            }}
          >
            In Stock
          </th>
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
