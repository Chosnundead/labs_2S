import React, { useState } from "react";
import { NewCalendar } from "./NewCalendar";
import { NewNotes } from "./NewNotes";
import { MyButton } from "./UI/button/MyButton";

export const Scheduler = ({ children, ...props }) => {
  const [date, setDate] = useState(
    new Date(new Date().getFullYear(), new Date().getMonth())
  );

  const decrementDate = () => {
    setDate(new Date(date.getFullYear(), date.getMonth() - 1));
  };

  const incrementDate = () => {
    setDate(new Date(date.getFullYear(), date.getMonth() + 1));
  };

  const getAndSetCheckedDate = (numberOfDay) => {
    setDate(new Date(date.getFullYear(), date.getMonth(), numberOfDay));
  };

  const setNotesFromNewNotes = (title, body) => {
    setNotes([
      ...notes,
      { id: new Date(), date: date, title: title, body: body },
    ]);
  };

  const changeNotesFromNewNote = (id, body) => {
    let arr = [...notes];
    for (let index = 0; index < arr.length; index++) {
      if (arr[index].id === id) {
        arr[index].body = body;
      }
    }
    setNotes(arr);
  };

  const deleteNotesFromNewNote = (id) => {
    let arr = [...notes];
    for (let index = 0; index < arr.length; index++) {
      if (arr[index].id === id) {
        arr.splice(index, 1);
      }
    }
    setNotes(arr);
  };

  const [notes, setNotes] = useState([
    {
      id: new Date(),
      date: new Date(2022, 4, 11),
      title: "test",
      body: "test",
    },
  ]);

  return (
    <div>
      <p>{children}</p>
      <NewCalendar date={date} setCheckedDate={getAndSetCheckedDate} />
      <MyButton onClick={decrementDate}>Prev month</MyButton>
      <text style={{ margin: "0px 10px 0px 10px" }}>
        {date.getMonth() + 1}.{date.getFullYear()}
      </text>
      <MyButton onClick={incrementDate}>Next month</MyButton>
      <br />
      <MyButton
        onClick={(event) => {
          setNotes([]);
        }}
      >
        Delete all
      </MyButton>
      <NewNotes
        changeNotesFromNewNote={changeNotesFromNewNote}
        setNotesFromNewNotes={setNotesFromNewNotes}
        deleteNotesFromNewNote={deleteNotesFromNewNote}
        notes={notes.filter((item) => {
          return (
            date.getFullYear() === item.date.getFullYear() &&
            date.getMonth() === item.date.getMonth() &&
            date.getDate() === item.date.getDate()
          );
        })}
      />
    </div>
  );
};
