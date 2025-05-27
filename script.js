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
