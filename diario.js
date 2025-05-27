// Diario pagine
    const pages = document.querySelectorAll('.page');
    let currentPage = 0;

    function showPage(index) {
      pages.forEach((page, i) => {
        page.classList.remove('active');
        if (i === index) {
          page.classList.add('active');
        }
      });
    }

    document.getElementById('prevBtn').addEventListener('click', () => {
      currentPage = (currentPage - 1 + pages.length) % pages.length;
      showPage(currentPage);
    });

    document.getElementById('nextBtn').addEventListener('click', () => {
      currentPage = (currentPage + 1) % pages.length;
      showPage(currentPage);
    });

    // Avvia alla prima pagina
    showPage(currentPage);
