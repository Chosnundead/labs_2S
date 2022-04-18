import React from "react";
import { useState } from "react";
import "../styles/PhoneInput.css";
import InputMask from "react-input-mask";

const PhoneInput = function (props) {
  const [select, setSelect] = useState(false);
  const [country, setCountry] = useState("by");
  const [input, setInput] = useState("+999 (99) 999-99-99");
  const arrOfCountry = {
    by: {
      img: "https://eurasiangroup.org/files/images_original/b%D0%B5larusx_1547809530.gif",
    },
    ru: {
      img: "https://cdn.pixabay.com/photo/2012/04/23/16/36/flag-of-the-russian-federation-38922_960_720.png",
    },
    ua: {
      img: "https://upload.wikimedia.org/wikipedia/commons/4/49/Flag_of_Ukraine.svg",
    },
    pl: {
      img: "https://petrsu.ru/files/news_notice_event/2018/1/30/1517320923_polandflagmax500.gif",
    },
    lt: {
      img: "https://upload.wikimedia.org/wikipedia/commons/thumb/1/11/Flag_of_Lithuania.svg/250px-Flag_of_Lithuania.svg.png",
    },
    lv: {
      img: "https://flags-world.com/wp-content/uploads/2021/01/flag-latvii-1.png",
    },
  };
  return (
    <div>
      <div
        style={{
          border: "2px solid silver",
          display: "inline-block",
        }}
      >
        <div
          style={{
            backgroundImage: `url('${arrOfCountry[country]["img"]}')`,
            backgroundRepeat: "round",
            padding: "19px",
            position: "absolute",
          }}
          onClick={(event) => {
            setSelect(!select);
          }}
        ></div>
        <InputMask
          className={`${props.dataId}`}
          id="inputNumber"
          mask={input}
          style={{
            outline: "none",
            border: "none",
            marginLeft: "36px",
            marginBottom: "0px",
            padding: "11px",
            width: "fit-content",
          }}
          onChange={(event) => {
            if (
              document
                .querySelector("#inputNumber")
                .value.replace(/[ ]/gi, "")
                .replace(/[_]/gi, "")
                .replace(/[(]/gi, "")
                .replace(/[)]/gi, "")
                .includes("+375")
            ) {
              setCountry("by");
              setInput("+999 (99) 999-99-99");
            } else if (
              document
                .querySelector("#inputNumber")
                .value.replace(/[ ]/gi, "")
                .replace(/[_]/gi, "")
                .replace(/[(]/gi, "")
                .replace(/[)]/gi, "")
                .includes("+7")
            ) {
              setCountry("ru");
              setInput("+9 (999) 999-99-99");
            } else if (
              document
                .querySelector("#inputNumber")
                .value.replace(/[ ]/gi, "")
                .replace(/[_]/gi, "")
                .replace(/[(]/gi, "")
                .replace(/[)]/gi, "")
                .includes("+380")
            ) {
              setCountry("ua");
              setInput("+999 (99) 999-99-99");
            } else if (
              document
                .querySelector("#inputNumber")
                .value.replace(/[ ]/gi, "")
                .replace(/[_]/gi, "")
                .replace(/[(]/gi, "")
                .replace(/[)]/gi, "")
                .includes("+48")
            ) {
              setCountry("pl");
              setInput("+99 999-999-999");
            } else if (
              document
                .querySelector("#inputNumber")
                .value.replace(/[ ]/gi, "")
                .replace(/[_]/gi, "")
                .replace(/[(]/gi, "")
                .replace(/[)]/gi, "")
                .includes("+370")
            ) {
              setCountry("lt");
              setInput("+999 (99) 999-99-99");
            } else if (
              document
                .querySelector("#inputNumber")
                .value.replace(/[ ]/gi, "")
                .replace(/[_]/gi, "")
                .replace(/[(]/gi, "")
                .replace(/[)]/gi, "")
                .includes("+371")
            ) {
              setCountry("lv");
              setInput("+999 9999-9999");
            }
          }}
        ></InputMask>
      </div>
      {select && (
        <ul className="country-list">
          <li
            onClick={(event) => {
              setCountry("by");
              setSelect(false);
              setInput("");
              document.querySelector("#inputNumber").value = "+375";
            }}
          >
            Беларусь
          </li>
          <li
            onClick={(event) => {
              setCountry("ru");
              setSelect(false);
              setInput("");
              document.querySelector("#inputNumber").value = "+7";
            }}
          >
            Россия
          </li>
          <li
            onClick={(event) => {
              setCountry("ua");
              setSelect(false);
              setInput("");
              document.querySelector("#inputNumber").value = "+380";
            }}
          >
            Украина
          </li>
          <li
            onClick={(event) => {
              setCountry("pl");
              setSelect(false);
              setInput("");
              document.querySelector("#inputNumber").value = "+48";
            }}
          >
            Польша
          </li>
          <li
            onClick={(event) => {
              setCountry("lt");
              setSelect(false);
              setInput("");
              document.querySelector("#inputNumber").value = "+370";
            }}
          >
            Литва
          </li>
          <li
            onClick={(event) => {
              setCountry("lv");
              setSelect(false);
              setInput("");
              document.querySelector("#inputNumber").value = "+371";
            }}
          >
            Латвия
          </li>
        </ul>
      )}
    </div>
  );
};

export default PhoneInput;
