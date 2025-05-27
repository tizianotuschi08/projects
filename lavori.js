document.addEventListener("DOMContentLoaded", function () {
  const tableBody = document.querySelector("#lavori-table-body");

  const descrizioni = {
    "Progetto1": "Esercizi base",
    "asta_tuschi": "Simulazione di un'asta",
    ...
  };

  fetch("https://api.github.com/repos/tizianotuschi08/projects/contents")
    .then(response => response.json())
    .then(data => {
      data.forEach(item => {
        if (item.type === "dir") {
          const nome = item.name;
          const descrizione = descrizioni[nome] || "Descrizione non disponibile";
          const downloadLink = `https://github.com/tizianotuschi08/projects/tree/main/${nome}`;

          const row = document.createElement("tr");
          row.innerHTML = `
            <td>${nome}</td>
            <td>${descrizione}</td>
            <td><a href="${downloadLink}" target="_blank">Vai alla cartella</a></td>
          `;
          tableBody.appendChild(row);
        }
      });
    });
});
