#pragma once

#ifndef _SATISFACTORY_HXX_
#define _SATISFACTORY_HXX_

#include <map>
#include "Item.Hxx"
#include "Recipe.Hxx"
#include "Building.Hxx"
#include "ItemTable.Hxx"
#include "RecipeTable.Hxx"
#include "BuildingTable.Hxx"

#define NAME_OF(var) #var

namespace Satisfactory {

	namespace Items {

		//==============================================================================================|  Ores

		extern Item* Limestone;
		extern Item* IronOre;
		extern Item* CopperOre;
		extern Item* CateriumOre;
		extern Item* Coal;
		extern Item* RawQuartz;
		extern Item* Sulfur;
		extern Item* Bauxite;
		extern Item* SAMOre;
		extern Item* Uranium;

		//==============================================================================================|  Ingots
		extern Item* IronIngot;
		extern Item* CopperIngot;
		extern Item* CateriumIngot;
		extern Item* SteelIngot;
		extern Item* AluminumIngot;

		//==============================================================================================|  Minerals
		extern Item* Concrete;
		extern Item* QuartzCrystal;
		extern Item* Silica;
		extern Item* CopperPowder;
		extern Item* PolymerResin;
		extern Item* PetroleumCoke;
		extern Item* AluminumScrap;

		//==============================================================================================|  Aliens

		extern Item* AlienProtein;
		extern Item* AlienDNACapsule;

		//==============================================================================================|  Liquids

		extern Item* Water;
		extern Item* CrudeOil;
		extern Item* HeavyOilResidue;
		extern Item* Fuel;
		extern Item* LiquidBiofuel;
		extern Item* Turbofuel;
		extern Item* AluminaSolution;
		extern Item* SulfuricAcid;
		extern Item* NitriAcid;

		//==============================================================================================|  Gas

		extern Item* NitrogenGas;

		//==============================================================================================|  Standard Parts

		extern Item* IronRod;
		extern Item* Screw;
		extern Item* IronPlate;
		extern Item* ReinforcedIronPlate;
		extern Item* CopperSheet;
		extern Item* AlcladAluminumSheet;
		extern Item* AluminumCasing;
		extern Item* SteelPipe;
		extern Item* SteelBeam;
		extern Item* EncasedIndustrialBeam;
		extern Item* ModularFrame;
		extern Item* HeavyHodularFrame;
		extern Item* FusedModularFrame;
		extern Item* Fabric;
		extern Item* Plastic;
		extern Item* Rubber;

		//==============================================================================================|  Industrial Parts

		extern Item* Rotor;
		extern Item* Stator;
		extern Item* Battery;
		extern Item* Motor;
		extern Item* HeatSink;
		extern Item* CoolingSystem;
		extern Item* TurboMotor;

		//==============================================================================================|  Electronics

		extern Item* Wire;
		extern Item* Cable;
		extern Item* Quickwire;
		extern Item* CircuitBoard;
		extern Item* AILimiter;
		extern Item* HighSpeedConnector;

		//==============================================================================================|  Communications

		extern Item* Computer;
		extern Item* Supercomputer;
		extern Item* QuantumComputer;
		extern Item* RadioControlUnit;
		extern Item* CrystalOscillator;
		extern Item* SuperpositionOscillator;

		//==============================================================================================|  Containers

		extern Item* EmptyCanister;
		extern Item* EmptyFluidTank;
		extern Item* PressureConversionCube;
		extern Item* PackagedWater;
		extern Item* PackagedAluminaSolution;
		extern Item* PackagedSulfuricAcid;
		extern Item* PackagedNitricAcid;
		extern Item* PackagedNitrogenGas;

		//==============================================================================================|  Fuels

		extern Item* Leaves;
		extern Item* Mycelia;
		extern Item* FlowerPetals;
		extern Item* Wood;
		extern Item* Biomass;
		extern Item* CompactedCoal;
		extern Item* PackagedOil;
		extern Item* PackagedHeavyOilResidue;
		extern Item* SolidBiofuel;
		extern Item* PackagedFuel;
		extern Item* PackagedLiquidBiofuel;
		extern Item* PackagedTurbofuel;
		extern Item* UraniumFuelRod;
		extern Item* PlutoniumFuelRod;

		//==============================================================================================|  Consumed

		extern Item* BlackPowder;
		extern Item* SmokelessPowder;
		extern Item* GasFilter;
		extern Item* ColorCartrridge;
		extern Item* Beacon;
		extern Item* IodineInfusedFilter;

		//==============================================================================================|  Ammos

		extern Item* IronRebar;
		extern Item* StunRebar;
		extern Item* ShatterRebar;
		extern Item* ExplosiveRebar;
		extern Item* RifleAmmo;
		extern Item* HomingRifleAmmo;
		extern Item* TurboRifleAmmo;
		extern Item* Nobelisk;
		extern Item* GasNobelisk;
		extern Item* PulseNobelisk;
		extern Item* ClusterNobelisk;
		extern Item* NukeNobelisk;

		//==============================================================================================|  Nuclear

		extern Item* ElectromagneticControlRod;
		extern Item* EncasedUraniumCell;
		extern Item* NonFissileUranium;
		extern Item* PlutoniumPellet;
		extern Item* EncasedPlutoniumCell;

		//==============================================================================================|  Waste

		extern Item* UraniumWaste;
		extern Item* PlutoniumWaste;

		//==============================================================================================|  Special

		extern Item* BluePowerSlug;
		extern Item* YellowPowerSlug;
		extern Item* PurplePowerSlug;
		extern Item* PowerShard;
		extern Item* FICSITCoupon;
		extern Item* SmartPlating;
		extern Item* VersatileFramework;
		extern Item* AutomatedWiring;
		extern Item* ModularEngine;
		extern Item* AdaptiveControlUnit;
		extern Item* AssemblyDirectorSystem;
		extern Item* MagneticFieldGenerator;
		extern Item* ThermalPropulsionRocket;
		extern Item* NucleaerPasta;
	}

	namespace Buildings {

		//==============================================================================================| Extraction

		extern Building* MinerMk1;
		extern Building* MinerMk2;
		extern Building* MinerMk3;
		extern Building* OilExtractor;
		extern Building* WaterExtractor;
		extern Building* ResourceWellPressurizer;
		extern Building* ResourceWellExtractor;

		//==============================================================================================| Production

		extern Building* Smelter;
		extern Building* Foundry;
		extern Building* Constructor;
		extern Building* Assembler;
		extern Building* Manufacturer;
		extern Building* Refinery;
		extern Building* Packager;
		extern Building* Blender;
		extern Building* ParticleAccelerator;

		//==============================================================================================| Generators

		extern Building* BiomassBurner;
		extern Building* CoalGenerator;
		extern Building* FuelGenerator;
		extern Building* GeothermalGenerator;
		extern Building* NuclearPowerPlant;
		extern Building* PowerStorage;

		//==============================================================================================| Special

		extern Building* TheHUB;
		extern Building* MAM;
		extern Building* SpaceElevator;
		extern Building* BlueprintDesigner;
		extern Building* AWESOMESink;
		extern Building* AWESOMEShop;

		//==============================================================================================| Workstations

		extern Building* CraftBench;
		extern Building* EquipmentWorkshop;

		//==============================================================================================| Storage

		extern Building* PersonalStorageBox;
		extern Building* MedicalStorageBox;
		extern Building* HazardStorageBox;
		extern Building* StorageContainer;
		extern Building* IndustrialStorageContainer;
		extern Building* FluidBuffer;
		extern Building* IndustrialFluidBuffer;

		//==============================================================================================| DockingStations

		extern Building* TruckStation;
		extern Building* DronePort;
		extern Building* FreightPlatform;
		extern Building* FluidFreightPlatform;

		//==============================================================================================| Towers

		extern Building* LookoutTower;
		extern Building* RadarTower;

	}

	//namespace Recipes {

	//	//==============================================================================================| Ores

	//	extern Recipe* IronOre;

	//	//==============================================================================================| Ingots

	//	extern Recipe* IronIngot;
	//	extern Recipe* IronAlloyIngot;
	//	extern Recipe* PureIronIngot;
	//}


	extern std::map<std::string, Item*>     ItemList;
	extern std::map<std::string, Recipe*>   RecipeList;
	extern std::map<std::string, Building*> BuildingList;

	extern std::vector<Item*> PowerSources;

	void Initialize();

};


#endif