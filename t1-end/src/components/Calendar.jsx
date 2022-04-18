import React, { useState } from "react";

const Calendar = (props) => {
  function _createTable(pr) {
    let dateForTable = new Date(pr[0], pr[1]);
    setTrueDate(dateForTable);
    let arrCopy = [["вс", "пн", "вт", "ср", "чт", "пт", "сб"]];
    let month = dateForTable.getMonth();
    while (dateForTable.getMonth() == month) {
      let temp = [];
      for (let step = 0; step < 7; step++) {
        if (dateForTable.getDay() == step && dateForTable.getMonth() == month) {
          temp.push(dateForTable.getDate());
          dateForTable = new Date(
            dateForTable.getFullYear(),
            dateForTable.getMonth(),
            dateForTable.getDate() + 1
          );
        } else {
          temp.push("");
        }
      }
      arrCopy.push(temp);
    }
    return arrCopy;
  }
  function decreaseM() {
    setDate([
      date[1] == 0 ? date[0] - 1 : date[0],
      date[1] == 0 ? 11 : date[1] - 1,
    ]);
    setTable(_createTable(date));
  }
  function increaseM() {
    setDate([
      date[1] == 11 ? date[0] + 1 : date[0],
      date[1] == 11 ? 0 : date[1] + 1,
    ]);
    setTable(_createTable(date));
  }
  function getDay(event) {
    try {
      for (const item of document.getElementsByClassName(`cell`)) {
        item.setAttribute("style", "background-color: white");
      }
    } catch {}
    setDay(event.currentTarget.dataset.number);
    document
      .getElementById(`${event.currentTarget.dataset.number}`)
      .setAttribute("style", "background-color: red");
  }
  const [date, setDate] = useState([2022, 2]);
  const [table, setTable] = useState([[2121]]);
  const [day, setDay] = useState(0);
  const [trueDate, setTrueDate] = useState(new Date());
  return (
    <div>
      <table className="lab4test">
        <tbody>
          {table.map((arr) => {
            return (
              <tr>
                {arr.map((item) => {
                  return (
                    <td
                      onClick={getDay}
                      data-number={item}
                      id={item}
                      className="cell"
                    >
                      {item}
                    </td>
                  );
                })}
              </tr>
            );
          })}
        </tbody>
      </table>
      <button onClick={decreaseM}>click me-left</button>
      <button onClick={increaseM}>click me-right</button>
      <p>
        {trueDate.getFullYear()} / {trueDate.getMonth() + 1} / {day}
      </p>
    </div>
  );
};

export default Calendar;
