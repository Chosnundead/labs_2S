import React, { useState } from "react";
import classes from "../styles/NewCalendar.module.css";

export const NewCalendar = ({ setCheckedDate, ...props }) => {
  const createTableByDate = () => {
    let arr = [];
    arr.push(["Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"]);
    let date = new Date(props.date.getFullYear(), props.date.getMonth());
    while (date.getMonth() === props.date.getMonth()) {
      let rowOfTable = [];
      for (let day = 1; day <= 7 && day != 0; day++) {
        if (day === 7) {
          day = 0;
        }
        if (
          day === date.getDay() &&
          date.getMonth() === props.date.getMonth()
        ) {
          rowOfTable.push(date.getDate());
          date = new Date(
            date.getFullYear(),
            date.getMonth(),
            date.getDate() + 1
          );
        } else {
          rowOfTable.push("");
        }
        if (!day) {
          break;
        }
      }
      arr.push(rowOfTable);
    }
    console.log(arr);
    return arr;
  };

  let table = createTableByDate(props.date);
  let head = table.shift();

  return (
    <table className={classes.NewCalendar}>
      <thead>
        <tr>
          {head.map((item) => {
            return <td>{item}</td>;
          })}
        </tr>
      </thead>
      <tbody>
        {table.map((item) => {
          return (
            <tr style={{ border: "2px solid #69c" }}>
              {item.map((itemOfItem) => {
                return itemOfItem !== "" ? (
                  itemOfItem === props.date.getDate() ? (
                    <td
                      style={{
                        border: "2px solid #69c",
                        padding: "6px",
                        backgroundColor: "yellow",
                      }}
                      onClick={() => setCheckedDate(itemOfItem)}
                    >
                      {itemOfItem}
                    </td>
                  ) : (
                    <td
                      style={{ border: "2px solid #69c", padding: "6px" }}
                      onClick={() => setCheckedDate(itemOfItem)}
                    >
                      {itemOfItem}
                    </td>
                  )
                ) : (
                  <td style={{ border: "2px solid #69c", padding: "6px" }}>
                    {itemOfItem}
                  </td>
                );
              })}
            </tr>
          );
        })}
      </tbody>
    </table>
  );
};
