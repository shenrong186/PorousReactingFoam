
                IOdictionary overAllOptions
                 (
                 IOobject
                 (
                 "overAllOptions",
                 runTime.constant(),
                 runTime,
                 IOobject::MUST_READ,
                 IOobject::NO_WRITE
                 )
                 );

dimensionedScalar c_rad
(
    "c_rad",
    overAllOptions.lookup("c_rad")
);
dimensionedScalar c_radfix
(
    "c_radfix",
    overAllOptions.lookup("c_radfix")
);
dimensionedScalar h_lose
(
    "h_lose",
    overAllOptions.lookup("h_lose")
);

dimensionedScalar AoV_lose
(
    "AoV_lose",
    overAllOptions.lookup("AoV_lose")
);
