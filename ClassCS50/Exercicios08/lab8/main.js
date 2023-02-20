document.addEventListener('DOMContentLoaded', function () {
    let correct = document.querySelector('.correct');
    correct.addEventListener('click', function (event) {
        correct.style.backgroundColor = 'green';
        document.querySelector('#feedback1').innerHTML = 'Correct';
    });

    let incorrects = document.querySelectorAll('.incorrect');
    for (let i = 0; i < incorrects.length; i++) {
        incorrects[i].addEventListener('click', function (event) {
            incorrects[i].style.backgroundColor = 'red';
            document.querySelector('#feedback1').innerHTML = 'Incorrect';
        });
    }

    document.querySelector('#check').addEventListener('click', function () {
        let entrada = document.querySelector('entrada');
        if (entrada.value == 'RESPOSTA_CORRETA') {
            entrada.style.backgroundColor = 'green';
            document.querySelector('#feedback2').innerHTML = 'Correct';
        } else {
            entrada.style.backgroundColor = 'red';
            document.querySelector('#feedback2').innerHTML = 'Incorrect';
        }
    });
});