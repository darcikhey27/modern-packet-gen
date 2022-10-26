document.querySelector('#ethernet').addEventListener('click', get_ethernet);

const url_base = 'http://10.0.20.61:5000'

async function get_ethernet(event) {
    let url = url_base + '/l2/show/ether';
    let response = await fetch(url);
    let data = await response.json();
    let input_pkt = document.querySelector('#pkt')
    input_pkt.value = data.scapy_format;
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