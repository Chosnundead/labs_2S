import React, { useState } from "react";
import Note from "./Note";
import classes from "../styles/Notes.module.css";

const Notes = () => {
  const [list, setList] = useState([
    { title: "test1", date: "2022", text: "text" },
    { title: "test2", date: "2121", text: "text" },
  ]);
  const [newList, setNewList] = useState(["", "", ""]);
  return (
    <div>
      <form>
        <p>
          Заголовок
          <input
            value={newList[0]}
            onChange={(event) => {
              setNewList([event.target.value, newList[1], newList[2]]);
            }}
          />
        </p>
        <p>
          Дата
          <input
            type="date"
            value={newList[1]}
            onChange={(event) => {
              setNewList([newList[0], event.target.value, newList[2]]);
            }}
          />
        </p>
        <p>
          Текст
          <input
            value={newList[2]}
            onChange={(event) => {
              setNewList([newList[0], newList[1], event.target.value]);
            }}
          />
        </p>
        <p>
          <button
            className={classes.Notes}
            onClick={(event) => {
              event.preventDefault();
              console.log(newList);
              setList([
                ...list,
                { title: newList[0], date: newList[1], text: newList[2] },
              ]);
              setNewList(["", "", ""]);
            }}
          >
            Add
          </button>
          {list.length >= 3 && (
            <button
              className={classes.Notes}
              onClick={(event) => {
                event.preventDefault();
                let temp = list.slice(0);
                temp.shift();
                setList(temp);
              }}
            >
              Delete first
            </button>
          )}
          {list.length >= 3 && (
            <button
              className={classes.Notes}
              onClick={(event) => {
                event.preventDefault();
                let temp = list.slice(0);
                temp.pop();
                setList(temp);
              }}
            >
              Delete last
            </button>
          )}
        </p>
      </form>
      {list.length >= 9 && <p>У вас слишком много заметок!</p>}
      <div>
        {list.map((item, index) => {
          return (
            <Note
              title={item["title"]}
              date={item["date"]}
              text={item["text"]}
              size={index}
            />
          );
        })}
      </div>
    </div>
  );
};

export default Notes;
