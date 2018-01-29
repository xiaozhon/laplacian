configuration ExcitationC{
  provides{
    interface Power as volt25;
    interface Power as volt33;
    interface Power as volt50;
  }
}implementation{
    components ExcitationP, MainC;
    components MicaBusC;

    MainC.SoftwareInit -> ExcitationP.Init;

    ExcitationP.FiveVolt -> MicaBusC.PW5;
    ExcitationP.ThreeVolt -> MicaBusC.PW3;
    ExcitationP.VoltageBuffer -> MicaBusC.PW2;
    ExcitationP.VoltageBooster -> MicaBusC.PW1;
    ExcitationP.Amplifiers -> MicaBusC.PW6;
    ExcitationP.PW4 -> MicaBusC.PW4;

    volt25 = ExcitationP.volt25;
    volt33 = ExcitationP.volt33;
    volt50 = ExcitationP.volt50;  
}
    
