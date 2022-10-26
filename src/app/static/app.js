
const { createApp } = Vue 
import ProtocolButton from './components/ProtocolButton.js'

const protocols = {
  make: 'Ford',
  model: 'Mustang',
  year: 1969
};
currentProtocols = [
  {
    ethernet: {
    name: 'Ethernet',
    toStr: 'Ether()'},
    id: 1,
  },
  {
    arp: {
      name: 'ARP',
      toStr: 'ARP()'},
      id: 2,
  },
]

const TaskApp = {
  components: {
    ProtocolButton,
  },

  template: `
    <button @click="count++">
      You clicked me {{ count }} times.
    </button>
    <protocol-button class="button" button-text="Ethernet"></protocol-button>
    `,

  data() {
    return {
      message: 'Hello from VueJs',
      count: 0,
    }
  },
  // delimiters: ['{', '}'],

  methods: {
    test() {
      console.log("test methods");
      return "this";
    },
  }

  
}

createApp(TaskApp).mount('#app')