const url_base = 'http://10.0.20.61:5000'
let pktBuilderString = '';
let pktBuilderPreviewString = ''
document.addEventListener("DOMContentLoaded", function(event) {
    // Your code to run since DOM is loaded and ready
    console.log('document ready');
    initEvents();
});

function initEvents() {
    // returns a nodelist of buttons
    let btns = document.querySelectorAll('.button');
    btns.forEach(btn =>  {
        btn.addEventListener('click', bntClick);
    });
}

function bntClick(ev) {
    console.log(ev.target.id);
    if (ev.target.id === 'ether') {
        getEther();
    } else if (ev.target.id === 'dot1q') {
        console.log('update dot1q');
    } else if (ev.target.id === 'ip') {
        console.log('update ip');
    } else if (ev.target.id === 'ipv6') {
        console.log('update ipv6');
    } else if (ev.target.id === 'arp') {
        getArp(ev);
        console.log('update arp');
    } else if (ev.target.id === 'udp') {
        console.log('update upd');
    } else if (ev.target.id === 'tcp') {
        console.log('update tcp');
    } else if (ev.target.id === 'icmp') {
        console.log('update icmp')
    } else {
        console.log('others...')
    }

}

function makeGetRequest(url) {
    return fetch(url)
        .then((response) => response.json())
        .then((data) => {
                return data;
        });
}
function updateInputValue(newValue) {
    let input = document.querySelector('#pkt');
    let currentValue = input.value;
    console.log('currentValue ' + currentValue + ' newValue ' + newValue);
    if (pktBuilderString === '' && currentValue === '') {
        pktBuilderString = newValue
        currentValue = newValue;
    } else {
        if (!input.value.endsWith('/')) {
            currentValue = currentValue.concat('/', currentValue);
            console.log(currentValue)
            //input.value = input.value.concat('/', input.value);
        }
        input.value += newValue
        pktBuilderString += newValue;
    }
}
async function getArp() {
    let jsonData =  await makeGetRequest(url_base + '/arp');
    console.log(jsonData);
    //updateInputValue(jsonData.scapy_format)
}

 async function getEther(event) {
    let data = await makeGetRequest(url_base + '/ether');
    console.log(data);
}

// function foo(ev) {
//     fetch(url_base + '/l2/show/ether')
//     .then(
//         function(response) {
//             if (response.status !== 200) {
//                 console.log('Looks like there was a problem. Status Code: ' + 
//                         response.status);
//                 return;
//             }

//             // Examine the text in the response
//             response.json().then(function(data) {
//             console.log(data);
//             });
//         }
//     )
//     .catch(function(err) {
//         console.log('Fetch Error :-S', err);
//     });
// }