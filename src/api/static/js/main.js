
$(document).ready((init))

function init() {
    showInterfacesList();
}
    
    

function showInterfacesList() {
    // call flask api for a list of interfaces on the system
    interface = "<option>eth0</option>"
    $(".interface_list").append(interface)
}