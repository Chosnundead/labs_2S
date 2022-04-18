import React from "react";
import { createElement } from "react";
import { useState } from "react";
import "../styles/TableOfStocks.css";

const TableOfStocks = () => {
  const [parse, setParse] = useState([
    {
      stock_name: "EFX",
      company_name: "Equifax Inc",
      price: 163.55,
      currency: "USD",
      change: "+9.03",
    },
    {
      stock_name: "IRM",
      company_name: "Iron Mountain Inc",
      price: 33.21,
      currency: "USD",
      change: "+1.42",
    },
    {
      stock_name: "NTAP",
      company_name: "NetApp Inc",
      price: 54.81,
      currency: "USD",
      change: "-6.01",
    },
    {
      stock_name: "CTL",
      company_name: "Centurylink Inc",
      price: 13.79,
      currency: "USD",
      change: "-1.37",
    },
  ]);

  return (
    <table className="tableOfStocks">
      <thead>
        <tr>
          <th>Stock name</th>
          <th>Company name</th>
          <th>Price</th>
          <th>Currency</th>
          <th>Change</th>
        </tr>
      </thead>
      <tbody>
        {parse.map((one) => (
          <tr>
            <td>{one.stock_name}</td>
            <td>{one.company_name}</td>
            <td>{one.price}</td>
            <td>{one.currency}</td>
            {Number(one.change) >= 0 && <td className="green">{one.change}</td>}
            {Number(one.change) < 0 && <td className="red">{one.change}</td>}
          </tr>
        ))}
      </tbody>
    </table>
  );
};

export default TableOfStocks;
