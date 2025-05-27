//Mobile menu
function toggleMobileMenu() {
  document.getElementById("mobileMenu").classList.toggle("open");
}

// Modali
    function openModal(id) {
      document.getElementById(id).style.display = 'block';
    }

    function closeModal(id) {
      document.getElementById(id).style.display = 'none';
    }

    window.onclick = function(event) {
      if (event.target.classList.contains('modal')) {
        event.target.style.display = "none";
      }
    }

    function scrollToTop() {
      window.scrollTo({ top: 0, behavior: 'smooth' });
    }

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
