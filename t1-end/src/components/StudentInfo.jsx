import React, { useState } from "react";
import SignUpEmailInput from "./SignUpEmailInput";
import "../styles/style.css";

import PhoneInput from "./PhoneInput";

const StudentInfo = (props) => {
  const [table, setTable] = useState({
    name: null,
    date: "2022-12-21",
    year: null,
    faculty: null,
    group: null,
    speciality: null,
    email: "null@null",
    number: "+375(29)8750375",
  });
  const [isValid, setIsValid] = useState(false);
  const _changeIsValid = (props) => {
    setIsValid(props);
  };
  //   const id = props.dataId;
  const id = "test";
  const _isValid = (event) => {
    event.preventDefault();
    let temp = {
      name: null,
      date: "2022-12-21",
      year: null,
      faculty: null,
      group: null,
      speciality: null,
      email: "null@null",
      number: "+375(29)8750375",
    };
    temp["name"] = document.getElementsByClassName(`${id}name`)[0].value;
    temp["date"] = document.getElementsByClassName(`${id}date`)[0].value;
    temp["year"] = document.getElementsByClassName(`${id}year`)[0].value;
    temp["faculty"] = document.getElementsByClassName(`${id}faculty`)[0].value;
    temp["group"] = document.getElementsByClassName(`${id}group`)[0].value;
    temp["speciality"] = document.getElementsByClassName(
      `${id}speciality`
    )[0].value;
    temp["email"] = document.getElementsByClassName(`${id}email`)[0].value;
    temp["number"] = document.getElementsByClassName(`${id}number`)[0].value;
    setTable(temp);
  };

  return (
    <div>
      <form>
        <p>
          ФИО
          <input className={`${id}name`} />
        </p>
        <p>
          Дата рождения
          <input type="date" className={`${id}date`} />
        </p>
        <p>
          Год поступления в университет
          <input className={`${id}year`} />
        </p>
        <p>
          Факультет
          <input className={`${id}faculty`} />
        </p>
        <p>
          Группа
          <input className={`${id}group`} />
        </p>
        <p>
          Специальность
          <input className={`${id}speciality`} />
        </p>
        <SignUpEmailInput
          className={`${id}email`}
          dataFunction={_changeIsValid}
        />
        <p>
          Телефон
          <PhoneInput dataId={`${id}number`} />
        </p>
        <p>
          {isValid == true && <button onClick={_isValid}>Отправить</button>}
        </p>
      </form>
      {table["name"] != null && (
        <table>
          <tbody>
            <tr>
              <td>фио</td>
              <td>{table["name"]}</td>
            </tr>
            <tr>
              <td>текущий возраст студента</td>
              <td>
                {new Date().getFullYear() - Number(table["date"].slice(0, 4))}
              </td>
            </tr>
            <tr>
              <td>факультет, курс, группа</td>
              <td>
                {table["faculty"]}, {new Date().getFullYear() - table["year"]},{" "}
                {table["group"]}
              </td>
            </tr>
            <tr>
              <td>специальность</td>
              <td>{table["speciality"]}</td>
            </tr>
            <tr>
              <td>электронная почта</td>
              <td>{table["email"]}</td>
            </tr>
            <tr>
              <td>оператор услуг электронной почты</td>
              <td>
                {table["email"].slice(table["email"].lastIndexOf("@") + 1)}
              </td>
            </tr>
            <tr>
              <td>номер телефона</td>
              <td>{table["number"]}</td>
            </tr>
            <tr>
              <td>оператора услуг мобильной связи</td>
              {table["number"].slice(
                table["number"].indexOf("(") + 1,
                table["number"].indexOf(")")
              ) == "29" && <td>A1 (Velcom)</td>}
              {table["number"].slice(
                table["number"].indexOf("(") + 1,
                table["number"].indexOf(")")
              ) == "44" && <td>A1 (Velcom)</td>}
              {table["number"].slice(
                table["number"].indexOf("(") + 1,
                table["number"].indexOf(")")
              ) == "33" && <td>МТС</td>}
              {table["number"].slice(
                table["number"].indexOf("(") + 1,
                table["number"].indexOf(")")
              ) == "25" && <td>life:)</td>}
              {table["number"].slice(
                table["number"].indexOf("(") + 1,
                table["number"].indexOf(")")
              ) == "17" && <td>Белтелеком (городской)</td>}
            </tr>
          </tbody>
        </table>
      )}
    </div>
  );
};

export default StudentInfo;
