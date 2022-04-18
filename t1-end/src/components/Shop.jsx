import React, { useState } from "react";
import { Search } from "./Search";
import { Product } from "./Product";
import smartWatch0_0 from "../images/Shop/smartWatch0_0.jpg";
import smartWatch1_0 from "../images/Shop/smartWatch1_0.jpg";
import smartWatch2_0 from "../images/Shop/smartWatch2_0.jpg";
import smartWatch3_0 from "../images/Shop/smartWatch3_0.jpg";
import smartWatch3_1 from "../images/Shop/smartWatch3_1.jpg";

export const Shop = () => {
  const [goodsArray, setGoodsArray] = useState([
    {
      name: "Smart Watch IWO K8",
      price: 100,
      number: 666,
      images: [smartWatch0_0],
      description:
        "Smart Watch iwo k8 созданы для вас, если вы искренне фанатеете от всего, что делает компания Apple. Дизайн гаджета повторяет “яблочные” линии часов пятого поколения настолько детально, что отличить часы без близкого с ними знакомства от оригинала практически невозможно! Даже боковое зубчатое колесо не вызывает сомнений, не говоря уже о дисплее, ремешке и общем впечатлении.",
      isNew: false,
      discount: 8,
    },
    {
      name: "Умные часы Haylou Smart Watch 2 LS02",
      price: 140,
      number: 21,
      images: [smartWatch1_0],
      description:
        "Умные часы поддерживают 12 спортивных режимов. Купите Haylou 2 и наслаждайтесь точными результатами измерений во время занятий спортом. Haylou Smart Watch 2 LS02 оснащены оптическим датчиком измерения сердечных сокращений. В сочетании со специальным алгоритмом он способен идентифицировать изменения пульса в течение 24 часов.",
      isNew: false,
      discount: 21,
    },
    {
      name: "Фитнес-браслет Xiaomi Mi Smart Band 4",
      price: 50,
      number: 34,
      images: [smartWatch2_0],
      description:
        "Начать необходимо с того, 4-ый Mi Band наконец-то получил цветной сенсорный дисплей AMOLED. У 3-ей модели экран был монохромным. Дисплей стал почти на 40% больше, чем у предшественника, но назвать его большим (0.95 дюйма) по-прежнему трудно. Исчезла выемка для кнопки, которая была изюминкой 3-ей модели. Теперь верхняя часть плоская.",
      isNew: true,
      discount: 13,
    },
    {
      name: "Смарт-часы Samsung Galaxy Watch Active2",
      price: 275,
      number: 9,
      images: [smartWatch3_0, smartWatch3_1],
      description:
        "Поддержка Android, iOS, сенсорный экран, Super AMOLED, 1.2 , 360x360, Bluetooth, Wi-Fi, NFC.",
      isNew: true,
      discount: 9,
    },
  ]);
  const [typeOfSort, setTypeOfSort] = useState({
    search: "",
    select: "isNew",
    isStandartOrder: "true",
  });
  const _setTypeOfSortFromSearch = (typeOfSortFromSearch) => {
    setTypeOfSort(typeOfSortFromSearch);
  };
  function _sortFunction(array) {
    console.log(typeOfSort);
    if (typeOfSort.select === "") {
      return array;
    }
    return array.sort((itemOne, itemTwo) => {
      if (typeOfSort.isStandartOrder === "true") {
        if (typeOfSort.select === "name") {
          return itemOne[typeOfSort.select].localeCompare(
            itemTwo[typeOfSort.select]
          );
        }
        if (itemOne[typeOfSort.select] > itemTwo[typeOfSort.select]) {
          return -1;
        }
        if (itemOne[typeOfSort.select] < itemTwo[typeOfSort.select]) {
          return 1;
        }
        return 0;
      } else {
        if (typeOfSort.select === "name") {
          switch (
            itemOne[typeOfSort.select].localeCompare(itemTwo[typeOfSort.select])
          ) {
            case -1:
              return 1;
            case 1:
              return -1;
            case 0:
              return 0;
          }
        }
        if (itemOne[typeOfSort.select] > itemTwo[typeOfSort.select]) {
          return 1;
        }
        if (itemOne[typeOfSort.select] < itemTwo[typeOfSort.select]) {
          return -1;
        }
        return 0;
      }
    });
  }

  return (
    <div>
      <Search _setTypeOfSortFromSearch={_setTypeOfSortFromSearch} />
      <hr style={{ marginTop: "20px", marginBottom: "20px" }} />
      <div
        style={{
          display: "flex",
          flexDirection: "column",
          alignItems: "center",
        }}
      >
        {_sortFunction(
          goodsArray.filter((item) => {
            if (typeOfSort.search !== "") {
              return item.name
                .toLocaleLowerCase()
                .includes(typeOfSort.search.toLocaleLowerCase());
            } else {
              return true;
            }
          })
        ).map((item) => {
          return <Product product={item} />;
        })}
      </div>
    </div>
  );
};
