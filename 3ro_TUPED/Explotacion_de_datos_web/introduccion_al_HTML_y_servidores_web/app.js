url = document.currentScript.getAttribute('url');
fetch(url, { method: 'GET' })
  .then(response => {
    //Print the content of url in the HTML page
    document.body.append('Fin de tabla');    
    const headers = response.headers;
    const table = document.createElement('table');
    const tr = document.createElement('tr');
    const th1 = document.createElement('th');
    th1.textContent = 'Clave';
    const th2 = document.createElement('th');
    th2.textContent = 'Valor';
    tr.appendChild(th1)
    tr.appendChild(th2);
    table.appendChild(tr);

    headers.forEach((valor, clave) => {
      const tr = document.createElement('tr');
      const td1 = document.createElement('td');
      td1.textContent = clave;
      const td2 = document.createElement('td');
      td2.textContent = valor;
      tr.appendChild(td1);
      tr.appendChild(td2);
      table.appendChild(tr);
    });
    document.body.appendChild(table);
  })
  .catch(error => console.error(error));