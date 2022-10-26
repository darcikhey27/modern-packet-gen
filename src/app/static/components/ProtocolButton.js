export default {
  props: {
    buttonName: String,
    buttonClass: String,
    buttonText: String,

  },
  template: `
  <button @click=buttonClicked>{{buttonText}}</button>
  `,

  methods: {
    buttonClicked() {
      console.log(this.buttonText);
    }
    ,
  }
}
