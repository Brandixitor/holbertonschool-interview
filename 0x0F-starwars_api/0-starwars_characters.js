#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];
request.get(url, async (error, res) => {
  if (error) console.log(error);
  else {
    const list = JSON.parse(res.body);
    Execute(list.characters, 0);
  }
});

const Execute = (list, index) => {
  request.get(list[index], (error, res, body) => {
    if (error) throw error;
    const result = JSON.parse(body);
    console.log(result.name);
    if (index < list.length - 1) {
      Execute(list, index + 1);
    }
  });
};
