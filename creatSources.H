

    combustionModels::rhoCombustionModel& reactiontemp = reactionFluid[i];
    rhoReactionThermo& thermoFluidtemp = reactiontemp.thermo();
    solidThermo& thermoSolidtemp = thermos[i];
    volScalarField& heatTransfer = heatTransfers[i];
    volVectorField& Ut = UFluid[i];
    volScalarField& NuFluid = NuFluids[i];
    volScalarField& htransferFluid=htransferFluids[i];
    compressible::turbulenceModel& turbt = turbulence[i];
    volScalarField& REnumber = REnumbers[i];
    dimensionedScalar& dm = fdms[i];
    REnumber=thermoFluidtemp.rho()*mag(Ut)*dm/turbt.mu();
    dimensionedScalar& c_Nu = fc_Nus[i];
    dimensionedScalar& m_Nu = fm_Nus[i];
    dimensionedScalar& porosity = fporositys[i];
    NuFluid=c_Nu*pow(REnumber,m_Nu);
    htransferFluid=NuFluid*thermoFluidtemp.kappa()/dm/dm;
    volScalarField& TFluid = thermoFluidtemp.T();
    volScalarField& TSolid = thermoSolidtemp.T();
    volScalarField& Hlose = Hloses[i];
    volScalarField& T_en = T_ens[i];
    volScalarField& fix = fixs[i];
    heatTransfer=htransferFluid*(TFluid-TSolid);
    volScalarField& kappaAdd = kappaAdds[i];
    volScalarField& kka = kkas[i];
    kappaAdd=16*c_rad*TSolid*TSolid*TSolid/3/((3/dm)*(1-porosity));
    kka=kappaAdd/thermoSolidtemp.kappa();
    Hlose=h_lose*AoV_lose*(TSolid-T_en)+0.4*c_rad*AoV_lose*(TSolid*TSolid*TSolid*TSolid-T_en*T_en*T_en*T_en)+fix*0.8*c_rad*AoV_lose*(TSolid*TSolid*TSolid*TSolid-T_en*T_en*T_en*T_en);


