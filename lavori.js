document.addEventListener("DOMContentLoaded", function () {
    const tableBody = document.querySelector("#lavori-table-body");

    const descrizioni = {
      "Progetto1": "Esercizi base",
      "asta_tuschi": "Simulazione di un'asta",
      "calciatori_tuschi": "Gestione di una squadra di calciatori",
      "collatz_tuschi": "Algoritmo per la legge di collatz",
      "matrice-quadrata_tuschi": "Calcoli con una matrice quadratica",
      "mcm-mcd_tuschi": "Calcolo MCM e MCD di due numeri",
      "numeri-belga_tuschi": "Algoritmo per il calcolo di numeri belga",
      "numeri-univoci_tuschi":"Ricerca di numeri ripetuti in una matrice",
      "numeri-vampiro_tuschi":"Algoritmo per calcoli di numeri vampiro",
      "stadio_tuschi":"Gestione dei biglietti di uno stadio",
      "temperatura_tuschi": "Calcolo della differenza di temperatura",
      "tiro-dadi_tuschi":"Lancio di n dadi con calcolo di media",
      "voto-ristorante_tuschi":"Gestione delle recensioni di ristoranti",
        "strike&ball_tuschi":"Algoritmo per gioco strike&ball (indovina la combinazione)",
        "calcolo-stagioni_tuschi":"Algoritmo per sapere la stagione corrispondente al mese",
      // Aggiungi qui le descrizioni per ogni esercizio
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
              <td style="padding: 0.75rem; text-align: center;">${nome}</td>
              <td style="padding: 0.75rem; text-align: center;">${descrizione}</td>
              <td style="padding: 0.75rem; text-align: center;">
                <a href="${downloadLink}" target="_blank">Vai alla cartella</a>
              </td>
            `;
            tableBody.appendChild(row);
          }
        });
      })
      .catch(error => {
        console.error("Errore nel caricamento della repository GitHub:", error);
      });
  });
