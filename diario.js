const pages = document.querySelectorAll('.page');
let currentPage = 0;

// Crea i pallini dinamicamente
const dotsContainer = document.getElementById('pageDots');
pages.forEach((_, i) => {
  const dot = document.createElement('span');
  dot.classList.add('dot');
  if (i === currentPage) dot.classList.add('active-dot');
  dotsContainer.appendChild(dot);
});

function updateDots() {
  const dots = document.querySelectorAll('.dot');
  dots.forEach((dot, i) => {
    dot.classList.toggle('active-dot', i === currentPage);
  });
}

function showPage(index) {
  pages.forEach((page, i) => {
    page.classList.toggle('active', i === index);
  });
  updateDots();
}

document.getElementById('prevBtn').addEventListener('click', () => {
  currentPage = (currentPage - 1 + pages.length) % pages.length;
  showPage(currentPage);
});

document.getElementById('nextBtn').addEventListener('click', () => {
  currentPage = (currentPage + 1) % pages.length;
  showPage(currentPage);
});

// Navigazione con frecce tastiera
document.addEventListener('keydown', (e) => {
  if (e.key === 'ArrowLeft') {
    currentPage = (currentPage - 1 + pages.length) % pages.length;
    showPage(currentPage);
  } else if (e.key === 'ArrowRight') {
    currentPage = (currentPage + 1) % pages.length;
    showPage(currentPage);
  }
});

// Inizializza alla prima pagina
showPage(currentPage);
