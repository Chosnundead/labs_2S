import React, { useState } from "react";
import { Coment } from "./Coment";
import github from "../images/github.png";
import { ComentCreator } from "./ComentCreator";

export const Coments = () => {
  const [comentsArray, setComentsArray] = useState([
    {
      id: new Date(),
      name: "No Name",
      body: "text",
      password: "1234",
      avatar: github,
      eMail: "he@gmail.com",
    },
  ]);

  const addComentFromComentCreator = (coment) => {
    coment.id = new Date();
    setComentsArray([...comentsArray, coment]);
  };

  const deleteComentFromComent = (id) => {
    let comentsArrayCopy = [];
    for (const item of comentsArray) {
      if (!(id === item.id)) {
        comentsArrayCopy.push(item);
      }
    }
    setComentsArray(comentsArrayCopy);
  };

  const changeBodyFromComent = (coment) => {
    let comentsArrayCopy = [...comentsArray];
    for (const item of comentsArrayCopy) {
      if (coment.id === item.id) {
        item.body = coment.body;
        item.id = new Date();
      }
    }
    setComentsArray(comentsArrayCopy);
  };

  return (
    <div>
      <ComentCreator addComentFromComentCreator={addComentFromComentCreator} />
      {comentsArray.map((item) => {
        return (
          <Coment
            coment={item}
            changeBodyFromComent={changeBodyFromComent}
            deleteComentFromComent={deleteComentFromComent}
          />
        );
      })}
    </div>
  );
};
