#include "Satisfactory.Hxx"

namespace Satisfactory {

	namespace Items {

		//==============================================================================================|  Ores
		Item* Limestone = new Item;
		Item* IronOre = new Item;
		Item* CopperOre = new Item;
		Item* CateriumOre = new Item;
		Item* Coal = new Item;
		Item* RawQuartz = new Item;
		Item* Sulfur = new Item;
		Item* Bauxite = new Item;
		Item* SAMOre = new Item;
		Item* Uranium = new Item;

		//==============================================================================================|  Ingots
		Item* IronIngot = new Item;
		Item* CopperIngot = new Item;
		Item* CateriumIngot = new Item;
		Item* SteelIngot = new Item;
		Item* AluminumIngot = new Item;

		//==============================================================================================|  Minerals
		Item* Concrete = new Item;
		Item* QuartzCrystal = new Item;
		Item* Silica = new Item;
		Item* CopperPowder = new Item;
		Item* PolymerResin = new Item;
		Item* PetroleumCoke = new Item;
		Item* AluminumScrap = new Item;

		//==============================================================================================|  Aliens

		Item* AlienProtein = new Item;
		Item* AlienDNACapsule = new Item;

		//==============================================================================================|  Liquids

		Item* Water = new Item;
		Item* CrudeOil = new Item;
		Item* HeavyOilResidue = new Item;
		Item* Fuel = new Item;
		Item* LiquidBiofuel = new Item;
		Item* Turbofuel = new Item;
		Item* AluminaSolution = new Item;
		Item* SulfuricAcid = new Item;
		Item* NitriAcid = new Item;

		//==============================================================================================|  Gas

		Item* NitrogenGas = new Item;

		//==============================================================================================|  Standard Parts

		Item* IronRod = new Item;
		Item* Screw = new Item;
		Item* IronPlate = new Item;
		Item* ReinforcedIronPlate = new Item;
		Item* CopperSheet = new Item;
		Item* AlcladAluminumSheet = new Item;
		Item* AluminumCasing = new Item;
		Item* SteelPipe = new Item;
		Item* SteelBeam = new Item;
		Item* EncasedIndustrialBeam = new Item;
		Item* ModularFrame = new Item;
		Item* HeavyHodularFrame = new Item;
		Item* FusedModularFrame = new Item;
		Item* Fabric = new Item;
		Item* Plastic = new Item;
		Item* Rubber = new Item;

		//==============================================================================================|  Industrial Parts

		Item* Rotor = new Item;
		Item* Stator = new Item;
		Item* Battery = new Item;
		Item* Motor = new Item;
		Item* HeatSink = new Item;
		Item* CoolingSystem = new Item;
		Item* TurboMotor = new Item;

		//==============================================================================================|  Electronics

		Item* Wire = new Item;
		Item* Cable = new Item;
		Item* Quickwire = new Item;
		Item* CircuitBoard = new Item;
		Item* AILimiter = new Item;
		Item* HighSpeedConnector = new Item;

		//==============================================================================================|  Communications

		Item* Computer = new Item;
		Item* Supercomputer = new Item;
		Item* QuantumComputer = new Item;
		Item* RadioControlUnit = new Item;
		Item* CrystalOscillator = new Item;
		Item* SuperpositionOscillator = new Item;

		//==============================================================================================|  Containers

		Item* EmptyCanister = new Item;
		Item* EmptyFluidTank = new Item;
		Item* PressureConversionCube = new Item;
		Item* PackagedWater = new Item;
		Item* PackagedAluminaSolution = new Item;
		Item* PackagedSulfuricAcid = new Item;
		Item* PackagedNitricAcid = new Item;
		Item* PackagedNitrogenGas = new Item;

		//==============================================================================================|  Fuels

		Item* Leaves = new Item;
		Item* Mycelia = new Item;
		Item* FlowerPetals = new Item;
		Item* Wood = new Item;
		Item* Biomass = new Item;
		Item* CompactedCoal = new Item;
		Item* PackagedOil = new Item;
		Item* PackagedHeavyOilResidue = new Item;
		Item* SolidBiofuel = new Item;
		Item* PackagedFuel = new Item;
		Item* PackagedLiquidBiofuel = new Item;
		Item* PackagedTurbofuel = new Item;
		Item* UraniumFuelRod = new Item;
		Item* PlutoniumFuelRod = new Item;

		//==============================================================================================|  Consumed

		Item* BlackPowder = new Item;
		Item* SmokelessPowder = new Item;
		Item* GasFilter = new Item;
		Item* ColorCartrridge = new Item;
		Item* Beacon = new Item;
		Item* IodineInfusedFilter = new Item;

		//==============================================================================================|  Ammos

		Item* IronRebar = new Item;
		Item* StunRebar = new Item;
		Item* ShatterRebar = new Item;
		Item* ExplosiveRebar = new Item;
		Item* RifleAmmo = new Item;
		Item* HomingRifleAmmo = new Item;
		Item* TurboRifleAmmo = new Item;
		Item* Nobelisk = new Item;
		Item* GasNobelisk = new Item;
		Item* PulseNobelisk = new Item;
		Item* ClusterNobelisk = new Item;
		Item* NukeNobelisk = new Item;

		//==============================================================================================|  Nuclear

		Item* ElectromagneticControlRod = new Item;
		Item* EncasedUraniumCell = new Item;
		Item* NonFissileUranium = new Item;
		Item* PlutoniumPellet = new Item;
		Item* EncasedPlutoniumCell = new Item;

		//==============================================================================================|  Waste

		Item* UraniumWaste = new Item;
		Item* PlutoniumWaste = new Item;

		//==============================================================================================|  Special

		Item* BluePowerSlug = new Item;
		Item* YellowPowerSlug = new Item;
		Item* PurplePowerSlug = new Item;
		Item* PowerShard = new Item;
		Item* FICSITCoupon = new Item;
		Item* SmartPlating = new Item;
		Item* VersatileFramework = new Item;
		Item* AutomatedWiring = new Item;
		Item* ModularEngine = new Item;
		Item* AdaptiveControlUnit = new Item;
		Item* AssemblyDirectorSystem = new Item;
		Item* MagneticFieldGenerator = new Item;
		Item* ThermalPropulsionRocket = new Item;
		Item* NucleaerPasta = new Item;
	}

	namespace Buildings {

		//==============================================================================================| Extraction

		Building* MinerMk1 = new Building;
		Building* MinerMk2 = new Building;
		Building* MinerMk3 = new Building;
		Building* OilExtractor = new Building;
		Building* WaterExtractor = new Building;
		Building* ResourceWellPressurizer = new Building;
		Building* ResourceWellExtractor = new Building;

		//==============================================================================================| Production

		Building* Smelter = new Building;
		Building* Foundry = new Building;
		Building* Constructor = new Building;
		Building* Assembler = new Building;
		Building* Manufacturer = new Building;
		Building* Refinery = new Building;
		Building* Packager = new Building;
		Building* Blender = new Building;
		Building* ParticleAccelerator = new Building;

		//==============================================================================================| Generators

		Building* BiomassBurner = new Building;
		Building* CoalGenerator = new Building;
		Building* FuelGenerator = new Building;
		Building* GeothermalGenerator = new Building;
		Building* NuclearPowerPlant = new Building;
		Building* PowerStorage = new Building;

		//==============================================================================================| Special

		Building* TheHUB = new Building;
		Building* MAM = new Building;
		Building* SpaceElevator = new Building;
		Building* BlueprintDesigner = new Building;
		Building* AWESOMESink = new Building;
		Building* AWESOMEShop = new Building;

		//==============================================================================================| Workstations

		Building* CraftBench = new Building;
		Building* EquipmentWorkshop = new Building;

		//==============================================================================================| Storage

		Building* PersonalStorageBox = new Building;
		Building* MedicalStorageBox = new Building;
		Building* HazardStorageBox = new Building;
		Building* StorageContainer = new Building;
		Building* IndustrialStorageContainer = new Building;
		Building* FluidBuffer = new Building;
		Building* IndustrialFluidBuffer = new Building;

		//==============================================================================================| DockingStations

		Building* TruckStation = new Building;
		Building* DronePort = new Building;
		Building* FreightPlatform = new Building;
		Building* FluidFreightPlatform = new Building;

		//==============================================================================================| Towers

		Building* LookoutTower = new Building;
		Building* RadarTower = new Building;

	}

	namespace Recipes {

		//==============================================================================================| Ores

		Recipe* IronOre;

		//==============================================================================================| Ingots

		Recipe* IronIngot;
		Recipe* IronAlloyIngot;
		Recipe* PureIronIngot;
	}




	std::map<std::string, Item*>     ItemList;
	std::map<std::string, Recipe*>   RecipeList;
	std::map<std::string, Building*> BuildingList;

	std::vector<Item*> PowerSources;






	void Initialize() {
	
		{
			{
				//==============================================================================================|  Ores

				ItemList["Limestone"] = Items::Limestone;
				ItemList["IronOre"] = Items::IronOre;
				ItemList["CopperOre"] = Items::CopperOre;
				ItemList["CateriumOre"] = Items::CateriumOre;
				ItemList["Coal"] = Items::Coal;
				ItemList["RawQuartz"] = Items::RawQuartz;
				ItemList["Sulfur"] = Items::Sulfur;
				ItemList["Bauxite"] = Items::Bauxite;
				ItemList["SAMOre"] = Items::SAMOre;
				ItemList["Uranium"] = Items::Uranium;

				//==============================================================================================|  Ingots

				ItemList["IronIngot"] = Items::IronIngot;
				ItemList["CopperIngot"] = Items::CopperIngot;
				ItemList["CateriumIngot"] = Items::CateriumIngot;
				ItemList["SteelIngot"] = Items::SteelIngot;
				ItemList["AluminumIngot"] = Items::AluminumIngot;

				//==============================================================================================|  Minerals

				ItemList["Concrete"] = Items::Concrete;
				ItemList["QuartzCrystal"] = Items::QuartzCrystal;
				ItemList["Silica"] = Items::Silica;
				ItemList["CopperPowder"] = Items::CopperPowder;
				ItemList["PolymerResin"] = Items::PolymerResin;
				ItemList["PetroleumCoke"] = Items::PetroleumCoke;
				ItemList["AluminumScrap"] = Items::AluminumScrap;

				//==============================================================================================|  Aliens

				ItemList["AlienProtein"] = Items::AlienProtein;
				ItemList["AlienDNACapsule"] = Items::AlienDNACapsule;

				//==============================================================================================|  Liquids

				ItemList["Water"] = Items::Water;
				ItemList["CrudeOil"] = Items::CrudeOil;
				ItemList["HeavyOilResidue"] = Items::HeavyOilResidue;
				ItemList["Fuel"] = Items::Fuel;
				ItemList["LiquidBiofuel"] = Items::LiquidBiofuel;
				ItemList["Turbofuel"] = Items::Turbofuel;
				ItemList["AluminaSolution"] = Items::AluminaSolution;
				ItemList["SulfuricAcid"] = Items::SulfuricAcid;
				ItemList["NitriAcid"] = Items::NitriAcid;

				//==============================================================================================|  Gas

				ItemList["NitrogenGas"] = Items::NitrogenGas;

				//==============================================================================================|  Standard Parts

				ItemList["IronRod"] = Items::IronRod;
				ItemList["Screw"] = Items::Screw;
				ItemList["IronPlate"] = Items::IronPlate;
				ItemList["ReinforcedIronPlate"] = Items::ReinforcedIronPlate;
				ItemList["CopperSheet"] = Items::CopperSheet;
				ItemList["AlcladAluminumSheet"] = Items::AlcladAluminumSheet;
				ItemList["AluminumCasing"] = Items::AluminumCasing;
				ItemList["SteelPipe"] = Items::SteelPipe;
				ItemList["SteelBeam"] = Items::SteelBeam;
				ItemList["EncasedIndustrialBeam"] = Items::EncasedIndustrialBeam;
				ItemList["ModularFrame"] = Items::ModularFrame;
				ItemList["HeavyHodularFrame"] = Items::HeavyHodularFrame;
				ItemList["FusedModularFrame"] = Items::FusedModularFrame;
				ItemList["Fabric"] = Items::Fabric;
				ItemList["Plastic"] = Items::Plastic;
				ItemList["Rubber"] = Items::Rubber;

				//==============================================================================================|  Industrial Parts

				ItemList["Rotor"] = Items::Rotor;
				ItemList["Stator"] = Items::Stator;
				ItemList["Battery"] = Items::Battery;
				ItemList["Motor"] = Items::Motor;
				ItemList["HeatSink"] = Items::HeatSink;
				ItemList["CoolingSystem"] = Items::CoolingSystem;
				ItemList["TurboMotor"] = Items::TurboMotor;

				//==============================================================================================|  Electronics

ItemList["Wire"] = Items::Wire;
ItemList["Cable"] = Items::Cable;
ItemList["Quickwire"] = Items::Quickwire;
ItemList["CircuitBoard"] = Items::CircuitBoard;
ItemList["AILimiter"] = Items::AILimiter;
ItemList["HighSpeedConnector"] = Items::HighSpeedConnector;

//==============================================================================================|  Communications

ItemList["Computer"] = Items::Computer;
ItemList["Supercomputer"] = Items::Supercomputer;
ItemList["QuantumComputer"] = Items::QuantumComputer;
ItemList["RadioControlUnit"] = Items::RadioControlUnit;
ItemList["CrystalOscillator"] = Items::CrystalOscillator;
ItemList["SuperpositionOscillator"] = Items::SuperpositionOscillator;

//==============================================================================================|  Containers

ItemList["EmptyCanister"] = Items::EmptyCanister;
ItemList["EmptyFluidTank"] = Items::EmptyFluidTank;
ItemList["PressureConversionCube"] = Items::PressureConversionCube;
ItemList["PackagedWater"] = Items::PackagedWater;
ItemList["PackagedAluminaSolution"] = Items::PackagedAluminaSolution;
ItemList["PackagedSulfuricAcid"] = Items::PackagedSulfuricAcid;
ItemList["PackagedNitricAcid"] = Items::PackagedNitricAcid;
ItemList["PackagedNitrogenGas"] = Items::PackagedNitrogenGas;

//==============================================================================================|  Fuels

ItemList["Leaves"] = Items::Leaves;
ItemList["Mycelia"] = Items::Mycelia;
ItemList["FlowerPetals"] = Items::FlowerPetals;
ItemList["Wood"] = Items::Wood;
ItemList["Biomass"] = Items::Biomass;
ItemList["CompactedCoal"] = Items::CompactedCoal;
ItemList["PackagedOil"] = Items::PackagedOil;
ItemList["PackagedHeavyOilResidue"] = Items::PackagedHeavyOilResidue;
ItemList["SolidBiofuel"] = Items::SolidBiofuel;
ItemList["PackagedFuel"] = Items::PackagedFuel;
ItemList["PackagedLiquidBiofuel"] = Items::PackagedLiquidBiofuel;
ItemList["PackagedTurbofuel"] = Items::PackagedTurbofuel;
ItemList["UraniumFuelRod"] = Items::UraniumFuelRod;
ItemList["PlutoniumFuelRod"] = Items::PlutoniumFuelRod;

//==============================================================================================|  Consumed

ItemList["BlackPowder"] = Items::BlackPowder;
ItemList["SmokelessPowder"] = Items::SmokelessPowder;
ItemList["GasFilter"] = Items::GasFilter;
ItemList["ColorCartrridge"] = Items::ColorCartrridge;
ItemList["Beacon"] = Items::Beacon;
ItemList["IodineInfusedFilter"] = Items::IodineInfusedFilter;

//==============================================================================================|  Ammos

ItemList["IronRebar"] = Items::IronRebar;
ItemList["StunRebar"] = Items::StunRebar;
ItemList["ShatterRebar"] = Items::ShatterRebar;
ItemList["ExplosiveRebar"] = Items::ExplosiveRebar;
ItemList["RifleAmmo"] = Items::RifleAmmo;
ItemList["HomingRifleAmmo"] = Items::HomingRifleAmmo;
ItemList["TurboRifleAmmo"] = Items::TurboRifleAmmo;
ItemList["Nobelisk"] = Items::Nobelisk;
ItemList["GasNobelisk"] = Items::GasNobelisk;
ItemList["PulseNobelisk"] = Items::PulseNobelisk;
ItemList["ClusterNobelisk"] = Items::ClusterNobelisk;
ItemList["NukeNobelisk"] = Items::NukeNobelisk;

//==============================================================================================|  Nuclear

ItemList["ElectromagneticControlRod"] = Items::ElectromagneticControlRod;
ItemList["EncasedUraniumCell"] = Items::EncasedUraniumCell;
ItemList["NonFissileUranium"] = Items::NonFissileUranium;
ItemList["PlutoniumPellet"] = Items::PlutoniumPellet;
ItemList["EncasedPlutoniumCell"] = Items::EncasedPlutoniumCell;

//==============================================================================================|  Waste

ItemList["UraniumWaste"] = Items::UraniumWaste;
ItemList["PlutoniumWaste"] = Items::PlutoniumWaste;

//==============================================================================================|  Special

ItemList["BluePowerSlug"] = Items::BluePowerSlug;
ItemList["YellowPowerSlug"] = Items::YellowPowerSlug;
ItemList["PurplePowerSlug"] = Items::PurplePowerSlug;
ItemList["PowerShard"] = Items::PowerShard;
ItemList["FICSITCoupon"] = Items::FICSITCoupon;
ItemList["SmartPlating"] = Items::SmartPlating;
ItemList["VersatileFramework"] = Items::VersatileFramework;
ItemList["AutomatedWiring"] = Items::AutomatedWiring;
ItemList["ModularEngine"] = Items::ModularEngine;
ItemList["AdaptiveControlUnit"] = Items::AdaptiveControlUnit;
ItemList["AssemblyDirectorSystem"] = Items::AssemblyDirectorSystem;
ItemList["MagneticFieldGenerator"] = Items::MagneticFieldGenerator;
ItemList["ThermalPropulsionRocket"] = Items::ThermalPropulsionRocket;
ItemList["NucleaerPasta"] = Items::NucleaerPasta;
			}
			{}
			{
				//==============================================================================================| Extraction

				BuildingList["MinerMk1"] = Buildings::MinerMk1;
				BuildingList["MinerMk2"] = Buildings::MinerMk2;
				BuildingList["MinerMk3"] = Buildings::MinerMk3;
				BuildingList["OilExtractor"] = Buildings::OilExtractor;
				BuildingList["WaterExtractor"] = Buildings::WaterExtractor;
				BuildingList["ResourceWellPressurizer"] = Buildings::ResourceWellPressurizer;
				BuildingList["ResourceWellExtractor"] = Buildings::ResourceWellExtractor;

				//==============================================================================================| Production

				BuildingList["Smelter"] = Buildings::Smelter;
				BuildingList["Foundry"] = Buildings::Foundry;
				BuildingList["Constructor"] = Buildings::Constructor;
				BuildingList["Assembler"] = Buildings::Assembler;
				BuildingList["Manufacturer"] = Buildings::Manufacturer;
				BuildingList["Refinery"] = Buildings::Refinery;
				BuildingList["Packager"] = Buildings::Packager;
				BuildingList["Blender"] = Buildings::Blender;
				BuildingList["ParticleAccelerator"] = Buildings::ParticleAccelerator;

				//==============================================================================================| Generators

				BuildingList["BiomassBurner"] = Buildings::BiomassBurner;
				BuildingList["CoalGenerator"] = Buildings::CoalGenerator;
				BuildingList["FuelGenerator"] = Buildings::FuelGenerator;
				BuildingList["GeothermalGenerator"] = Buildings::GeothermalGenerator;
				BuildingList["NuclearPowerPlant"] = Buildings::NuclearPowerPlant;
				BuildingList["PowerStorage"] = Buildings::PowerStorage;

				//==============================================================================================| Special

				BuildingList["TheHUB"] = Buildings::TheHUB;
				BuildingList["MAM"] = Buildings::MAM;
				BuildingList["SpaceElevator"] = Buildings::SpaceElevator;
				BuildingList["BlueprintDesigner"] = Buildings::BlueprintDesigner;
				BuildingList["AWESOMESink"] = Buildings::AWESOMESink;
				BuildingList["AWESOMEShop"] = Buildings::AWESOMEShop;

				//==============================================================================================| Workstations

				BuildingList["CraftBench"] = Buildings::CraftBench;
				BuildingList["EquipmentWorkshop"] = Buildings::EquipmentWorkshop;

				//==============================================================================================| Storage

				BuildingList["PersonalStorageBox"] = Buildings::PersonalStorageBox;
				BuildingList["MedicalStorageBox"] = Buildings::MedicalStorageBox;
				BuildingList["HazardStorageBox"] = Buildings::HazardStorageBox;
				BuildingList["StorageContainer"] = Buildings::StorageContainer;
				BuildingList["IndustrialStorageContainer"] = Buildings::IndustrialStorageContainer;
				BuildingList["FluidBuffer"] = Buildings::FluidBuffer;
				BuildingList["IndustrialFluidBuffer"] = Buildings::IndustrialFluidBuffer;

				//==============================================================================================| DockingStations

				BuildingList["TruckStation"] = Buildings::TruckStation;
				BuildingList["DronePort"] = Buildings::DronePort;
				BuildingList["FreightPlatform"] = Buildings::FreightPlatform;
				BuildingList["FluidFreightPlatform"] = Buildings::FluidFreightPlatform;

				//==============================================================================================| Towers

				BuildingList["LookoutTower"] = Buildings::LookoutTower;
				BuildingList["RadarTower"] = Buildings::RadarTower;
			}
		}



		//{
		//	{
		//
		//		{ //==============================================================================================| Ores
		//			Items::Limestone = new Item;
		//			Items::Limestone->Name = "Limestone";
		//			Items::Limestone->Description.push_back("Used for crafting.");
		//			Items::Limestone->Description.push_back("Basic resource mainly used for stable foundations.");
		//			Items::Limestone->Category = ItemCategory::Ores;
		//			Items::Limestone->MaxStackSize = 100;
		//			Items::Limestone->SinkPoint = 2;
		//			Satisfactory::ItemList.push_back(Items::Limestone);
		//		} {
		//			Items::IronOre = new Item;
		//			Items::IronOre->Name = "Iron Ore";
		//			Items::IronOre->Description.push_back("Used for crafting.");
		//			Items::IronOre->Description.push_back("The most essential basic resource.");
		//			Items::IronOre->Category = ItemCategory::Ores;
		//			Items::IronOre->MaxStackSize = 100;
		//			Items::IronOre->SinkPoint = 1;
		//			Satisfactory::ItemList.push_back(Items::IronOre);
		//		} {
		//			Items::CopperOre = new Item;
		//			Items::CopperOre->Name = "Copper Ore";
		//			Items::CopperOre->Description.push_back("Used for crafting.");
		//			Items::CopperOre->Description.push_back("Basic resource mainly used for electricity.");
		//			Items::CopperOre->Category = ItemCategory::Ores;
		//			Items::CopperOre->MaxStackSize = 100;
		//			Items::CopperOre->SinkPoint = 3;
		//			Satisfactory::ItemList.push_back(Items::CopperOre);
		//		} {
		//			Items::CateriumOre = new Item;
		//			Items::CateriumOre->Name = "Caterium Ore";
		//			Items::CateriumOre->Description.push_back("Caterium Ore is smelted into Caterium Ingots.");
		//			Items::CateriumOre->Description.push_back("Caterium Ingots are mostly used for advanced electronics.");
		//			Items::CateriumOre->Category = ItemCategory::Ores;
		//			Items::CateriumOre->MaxStackSize = 100;
		//			Items::CateriumOre->SinkPoint = 7;
		//			Satisfactory::ItemList.push_back(Items::CateriumOre);
		//		} {
		//			Items::Coal = new Item;
		//			Items::Coal->Name = "Coal";
		//			Items::Coal->Description.push_back("Mainly used as vehicles & coal generators and for steel production.");
		//			Items::Coal->Category = ItemCategory::Ores;
		//			Items::Coal->MaxStackSize = 100;
		//			Items::Coal->Energy = 300;
		//			Items::Coal->SinkPoint = 3;
		//			Satisfactory::ItemList.push_back(Items::Coal);
		//			Satisfactory::PowerSources.push_back(Items::Coal);
		//		} {
		//			Items::RawQuartz = new Item;
		//			Items::RawQuartz->Name = "Raw Quartz";
		//			Items::RawQuartz->Description.push_back("Raw Quartz can be processed into Quartz Crystals and Silica,");
		//			Items::RawQuartz->Description.push_back("which both offer a variety of applications.");
		//			Items::RawQuartz->Category = ItemCategory::Ores;
		//			Items::RawQuartz->MaxStackSize = 100;
		//			Items::RawQuartz->SinkPoint = 15;
		//			Satisfactory::ItemList.push_back(Items::RawQuartz);
		//		} {
		//			Items::Sulfur = new Item;
		//			Items::Sulfur->Name = "Sulfur";
		//			Items::Sulfur->Description.push_back("Sulfur is primarily used for Black Powder.");
		//			Items::Sulfur->Category = ItemCategory::Ores;
		//			Items::Sulfur->MaxStackSize = 100;
		//			Items::Sulfur->SinkPoint = 11;
		//			Satisfactory::ItemList.push_back(Items::Sulfur);
		//		} {
		//			Items::Bauxite = new Item;
		//			Items::Bauxite->Name = "Bauxite";
		//			Items::Bauxite->Description.push_back("Bauxite is used to produce Alumina,");
		//			Items::Bauxite->Description.push_back("which can be further refined into the Aluminum Scrap required to produce Aluminum Ingots");
		//			Items::Bauxite->Category = ItemCategory::Ores;
		//			Items::Bauxite->MaxStackSize = 100;
		//			Items::Bauxite->SinkPoint = 8;
		//			Satisfactory::ItemList.push_back(Items::Bauxite);
		//		} {
		//			Items::SAMOre = new Item;
		//			Items::SAMOre->Name = "S.A.M. Ore";
		//			Items::SAMOre->Description.push_back("Stange Alien Metal that glistens with new possibilities.");
		//			Items::SAMOre->Category = ItemCategory::Ores;
		//			Items::SAMOre->MaxStackSize = 50;
		//			Items::SAMOre->SinkPoint = 0;
		//			Satisfactory::ItemList.push_back(Items::SAMOre);
		//		} {
		//			Items::Uranium = new Item;
		//			Items::Uranium->Name = "Uranium";
		//			Items::Uranium->Description.push_back("Uranium is a radioactive element.");
		//			Items::Uranium->Description.push_back("Used to produce Encased Uranium Cells for Uranium Fuel Rods.");
		//			Items::Uranium->Radioactive = "Morderately";
		//			Items::Uranium->Category = ItemCategory::Ores;
		//			Items::Uranium->MaxStackSize = 100;
		//			Items::Uranium->SinkPoint = 35;
		//			Satisfactory::ItemList.push_back(Items::Uranium);
		//		}
		//
		//		{ //==============================================================================================| Ingots
		//			Items::IronIngot = new Item;
		//			Items::IronIngot->Name = "Iron Ingot";
		//			Items::IronIngot->Description.push_back("Used for crafting.");
		//			Items::IronIngot->Description.push_back("Crafted into the most basic parts.");
		//			Items::IronIngot->Category = ItemCategory::Ingots;
		//			Items::IronIngot->MaxStackSize = 100;
		//			Items::IronIngot->SinkPoint = 2;
		//			Satisfactory::ItemList.push_back(Items::IronIngot);
		//		} {
		//			Items::CopperIngot = new Item;
		//			Items::CopperIngot->Name = "Copper Ingot";
		//			Items::CopperIngot->Description.push_back("Used for crafting.");
		//			Items::CopperIngot->Description.push_back("Crafted into the most basic parts.");
		//			Items::CopperIngot->Category = ItemCategory::Ingots;
		//			Items::CopperIngot->MaxStackSize = 100;
		//			Items::CopperIngot->SinkPoint = 6;
		//			Satisfactory::ItemList.push_back(Items::CopperIngot);
		//		} {
		//			Items::CateriumIngot = new Item;
		//			Items::CateriumIngot->Name = "Caterium Ingot";
		//			Items::CateriumIngot->Description.push_back("Caterium Ingots are smelted from Caterium Ore.");
		//			Items::CateriumIngot->Description.push_back("Caterium Ingots are mostly used for advanced electronics.");
		//			Items::CateriumIngot->Category = ItemCategory::Ingots;
		//			Items::CateriumIngot->MaxStackSize = 100;
		//			Items::CateriumIngot->SinkPoint = 42;
		//			Satisfactory::ItemList.push_back(Items::CateriumIngot);
		//		} {
		//			Items::SteelIngot = new Item;
		//			Items::SteelIngot->Name = "Steel Ingot";
		//			Items::SteelIngot->Description.push_back("Steel Ingots are made from Iron Ore that's been smelted with Coal.");
		//			Items::SteelIngot->Description.push_back("They are made into several parts used in building construction.");
		//			Items::SteelIngot->Category = ItemCategory::Ingots;
		//			Items::SteelIngot->MaxStackSize = 100;
		//			Items::SteelIngot->SinkPoint = 8;
		//			Satisfactory::ItemList.push_back(Items::SteelIngot);
		//		} {
		//			Items::AluminumIngot = new Item;
		//			Items::AluminumIngot->Name = "Aluminum Ingot";
		//			Items::AluminumIngot->Description.push_back("Aluminum Ingots are made from Aluminum Scrap, which is refined from Alumina Solution.");
		//			Items::AluminumIngot->Description.push_back("Used to produce specialized aluminum-based parts.");
		//			Items::AluminumIngot->Category = ItemCategory::Ingots;
		//			Items::AluminumIngot->MaxStackSize = 100;
		//			Items::AluminumIngot->SinkPoint = 131;
		//			Satisfactory::ItemList.push_back(Items::AluminumIngot);
		//		}
		//	}
		//
		//	{
		//		{ //==============================================================================================| Production
		//			Buildings::Smelter = new Building;
		//			Buildings::Smelter->Name = "Smelter";
		//			Buildings::Smelter->Category = BuildingCategory::Production;
		//			Buildings::Smelter->PowerUsed = 4;
		//			Buildings::Smelter->Width = 6;
		//			Buildings::Smelter->Length = 9;
		//			Buildings::Smelter->Height = 10;
		//			Buildings::Smelter->Input = 1;
		//			Buildings::Smelter->Output = 1;
		//			Buildings::Smelter->Ingredients.emplace_back(Items::IronRod, 5);
		//			Buildings::Smelter->Ingredients.emplace_back(Items::Wire, 8);
		//			Satisfactory::BuildingList.push_back(Buildings::Smelter);
		//
		//		}
		//	}
		//	
		//
		//	{
		//
		//		//==============================================================================================| Ores
		//
		//		{
		//			Recipes::IronOre = new Recipe;
		//			Recipes::IronOre->Name = "Iron Ore";
		//			Recipes::IronOre->Building = Buildings::MinerMk1;
		//			Recipes::IronOre->AddOutput(Items::IronOre, 60, 1);
		//			Satisfactory::RecipeList.push_back(Recipes::IronOre);
		//		}
		//
		//		//==============================================================================================| Ingots
		//		{
		//			Recipes::IronIngot = new Recipe;
		//			Recipes::IronIngot->Name = "Iron Ingot";
		//			Recipes::IronIngot->Building = Buildings::Smelter;
		//			Recipes::IronIngot->AddInput(Items::IronOre, 30., 1);
		//			Recipes::IronIngot->AddOutput(Items::IronIngot, 30., 1);
		//			Satisfactory::RecipeList.push_back(Recipes::IronIngot);
		//		} //{
		//		//	Recipes::IronAlloyIngot = new Recipe;
		//		//	Recipes::IronAlloyIngot->Name = "Iron Alloy Ingot";
		//		//	Recipes::IronAlloyIngot->Building = Buildings::Foundry;
		//		//	Recipes::IronAlloyIngot->IsAlt = true;
		//		//	Recipes::IronAlloyIngot->AddInput(Items::IronOre, 20., 2);
		//		//	Recipes::IronAlloyIngot->AddInput(Items::CopperOre, 20., 2);
		//		//	Recipes::IronAlloyIngot->AddOutput(Items::IronIngot, 50., 5);
		//		//	Satisfactory::RecipeList.push_back(Recipes::IronAlloyIngot);
		//		//} //{
		//		//	Recipes::PureIronIngot = new Recipe;
		//		//	Recipes::PureIronIngot->Name = "Pure Iron Ingot";
		//		//	Recipes::PureIronIngot->Building = Buildings::Refinery;
		//		//	Recipes::PureIronIngot->IsAlt = true;
		//		//	Recipes::PureIronIngot->AddInput(Items::IronOre, 35., 7);
		//		//	Recipes::PureIronIngot->AddInput(Items::Water, 20., 4);
		//		//	Recipes::PureIronIngot->AddOutput(Items::IronIngot, 65., 13);
		//		//	Satisfactory::RecipeList.push_back(Recipes::PureIronIngot);
		//		//}
		//	}
		//}
	}
}
