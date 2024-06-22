#include "Satisfactory.Hxx"
#include <iostream>
namespace Satisfactory {

	namespace Items {

		// Ores
		Item* Limestone;
		Item* IronOre;
		Item* CopperOre;
		Item* CateriumOre;
		Item* Coal;
		Item* RawQuartz;
		Item* Sulfur;
		Item* Bauxite;
		Item* SAMOre;
		Item* Uranium;

		// Ingots
		Item* IronIngot;
		Item* CopperIngot;
		Item* CateriumIngot;
		Item* SteelIngot;
		Item* AluminumIngot;

		// Minerals
		Item* Concrete;
		Item* QuartzCrystal;
		Item* Silica;
		Item* CopperPowder;
		Item* PolymerResin;
		Item* PetroleumCoke;
		Item* AluminumScrap;

		// Aliens

		Item* AlienProtein;
		Item* AlienDNACapsule;

		// Liquids

		Item* Water;
		Item* CrudeOil;
		Item* HeavyOilResidue;
		Item* Fuel;
		Item* LiquidBiofuel;
		Item* Turbofuel;
		Item* AluminaSolution;
		Item* SulfuricAcid;
		Item* NitriAcid;

		// Gas

		Item* NitrogenGas;

		// Standard Parts

		Item* IronRod;
		Item* Screw;
		Item* IronPlate;
		Item* ReinforcedIronPlate;
		Item* CopperSheet;
		Item* AlcladAluminumSheet;
		Item* AluminumCasing;
		Item* SteelPipe;
		Item* SteelBeam;
		Item* EncasedIndustrialBeam;
		Item* ModularFrame;
		Item* HeavyHodularFrame;
		Item* FusedModularFrame;
		Item* Fabric;
		Item* Plastic;
		Item* Rubber;

		// Industrial Parts

		Item* Rotor;
		Item* Stator;
		Item* Battery;
		Item* Motor;
		Item* HeatSink;
		Item* CoolingSystem;
		Item* TurboMotor;

		// Electronics

		Item* Wire;
		Item* Cable;
		Item* Quickwire;
		Item* CircuitBoard;
		Item* AILimiter;
		Item* HighSpeedConnector;

		// Communications

		Item* Computer;
		Item* Supercomputer;
		Item* QuantumComputer;
		Item* RadioControlUnit;
		Item* CrystalOscillator;
		Item* SuperpositionOscillator;

		// Containers

		Item* EmptyCanister;
		Item* EmptyFluidTank;
		Item* PressureConversionCube;
		Item* PackagedWater;
		Item* PackagedAluminaSolution;
		Item* PackagedSulfuricAcid;
		Item* PackagedNitricAcid;
		Item* PackagedNitrogenGas;

		// Fuels

		Item* Leaves;
		Item* Mycelia;
		Item* FlowerPetals;
		Item* Wood;
		Item* Biomass;
		Item* CompactedCoal;
		Item* PackagedOil;
		Item* PackagedHeavyOilResidue;
		Item* SolidBiofuel;
		Item* PackagedFuel;
		Item* PackagedLiquidBiofuel;
		Item* PackagedTurbofuel;
		Item* UraniumFuelRod;
		Item* PlutoniumFuelRod;

		// Consumed

		Item* BlackPowder;
		Item* SmokelessPowder;
		Item* GasFilter;
		Item* ColorCartrridge;
		Item* Beacon;
		Item* IodineInfusedFilter;

		// Ammos

		Item* IronRebar;
		Item* StunRebar;
		Item* ShatterRebar;
		Item* ExplosiveRebar;
		Item* RifleAmmo;
		Item* HomingRifleAmmo;
		Item* TurboRifleAmmo;
		Item* Nobelisk;
		Item* GasNobelisk;
		Item* PulseNobelisk;
		Item* ClusterNobelisk;
		Item* NukeNobelisk;

		// Nuclear

		Item* ElectromagneticControlRod;
		Item* EncasedUraniumCell;
		Item* NonFissileUranium;
		Item* PlutoniumPellet;
		Item* EncasedPlutoniumCell;

		// Waste

		Item* UraniumWaste;
		Item* PlutoniumWaste;

		// Special

		Item* BluePowerSlug;
		Item* YellowPowerSlug;
		Item* PurplePowerSlug;
		Item* PowerShard;
		Item* FICSITCoupon;
		Item* SmartPlating;
		Item* VersatileFramework;
		Item* AutomatedWiring;
		Item* ModularEngine;
		Item* AdaptiveControlUnit;
		Item* AssemblyDirectorSystem;
		Item* MagneticFieldGenerator;
		Item* ThermalPropulsionRocket;
		Item* NucleaerPasta;
	}

	namespace Buildings {

		//==============================================================================================| Extraction

		Building* MinerMk1;
		Building* MinerMk2;
		Building* MinerMk3;
		Building* OilExtractor;
		Building* WaterExtractor;
		Building* ResourceWellPressurizer;
		Building* ResourceWellExtractor;

		//==============================================================================================| Production

		Building* Smelter;
		Building* Foundry;
		Building* Constructor;
		Building* Assembler;
		Building* Manufacturer;
		Building* Refinery;
		Building* Packager;
		Building* Blender;
		Building* ParticleAccelerator;

		//==============================================================================================| Generators

		//==============================================================================================| Special

		//==============================================================================================| Workstations

		//==============================================================================================| Storage

		//==============================================================================================| DockingStations

		//==============================================================================================| Towers
	}

	namespace Recipes {

		//==============================================================================================| Ores

		Recipe* IronOre;

		//==============================================================================================| Ingots

		Recipe* IronIngot;
		Recipe* IronAlloyIngot;
		Recipe* PureIronIngot;
	}

	std::vector<Item*>     ItemList;
	std::vector<Recipe*>   RecipeList;
	std::vector<Building*> BuildingList;

	std::vector<Item*> PowerSources;

	void Initialize() {
		{
			{

				{ //==============================================================================================| Ores
					Items::Limestone = new Item;
					Items::Limestone->Name = "Limestone";
					Items::Limestone->Description.push_back("Used for crafting.");
					Items::Limestone->Description.push_back("Basic resource mainly used for stable foundations.");
					Items::Limestone->Category = ItemCategory::Ores;
					Items::Limestone->MaxStackSize = 100;
					Items::Limestone->SinkPoint = 2;
					Satisfactory::ItemList.push_back(Items::Limestone);
				} {
					Items::IronOre = new Item;
					Items::IronOre->Name = "Iron Ore";
					Items::IronOre->Description.push_back("Used for crafting.");
					Items::IronOre->Description.push_back("The most essential basic resource.");
					Items::IronOre->Category = ItemCategory::Ores;
					Items::IronOre->MaxStackSize = 100;
					Items::IronOre->SinkPoint = 1;
					Satisfactory::ItemList.push_back(Items::IronOre);
				} {
					Items::CopperOre = new Item;
					Items::CopperOre->Name = "Copper Ore";
					Items::CopperOre->Description.push_back("Used for crafting.");
					Items::CopperOre->Description.push_back("Basic resource mainly used for electricity.");
					Items::CopperOre->Category = ItemCategory::Ores;
					Items::CopperOre->MaxStackSize = 100;
					Items::CopperOre->SinkPoint = 3;
					Satisfactory::ItemList.push_back(Items::CopperOre);
				} {
					Items::CateriumOre = new Item;
					Items::CateriumOre->Name = "Caterium Ore";
					Items::CateriumOre->Description.push_back("Caterium Ore is smelted into Caterium Ingots.");
					Items::CateriumOre->Description.push_back("Caterium Ingots are mostly used for advanced electronics.");
					Items::CateriumOre->Category = ItemCategory::Ores;
					Items::CateriumOre->MaxStackSize = 100;
					Items::CateriumOre->SinkPoint = 7;
					Satisfactory::ItemList.push_back(Items::CateriumOre);
				} {
					Items::Coal = new Item;
					Items::Coal->Name = "Coal";
					Items::Coal->Description.push_back("Mainly used as vehicles & coal generators and for steel production.");
					Items::Coal->Category = ItemCategory::Ores;
					Items::Coal->MaxStackSize = 100;
					Items::Coal->Energy = 300;
					Items::Coal->SinkPoint = 3;
					Satisfactory::ItemList.push_back(Items::Coal);
					Satisfactory::PowerSources.push_back(Items::Coal);
				} {
					Items::RawQuartz = new Item;
					Items::RawQuartz->Name = "Raw Quartz";
					Items::RawQuartz->Description.push_back("Raw Quartz can be processed into Quartz Crystals and Silica,");
					Items::RawQuartz->Description.push_back("which both offer a variety of applications.");
					Items::RawQuartz->Category = ItemCategory::Ores;
					Items::RawQuartz->MaxStackSize = 100;
					Items::RawQuartz->SinkPoint = 15;
					Satisfactory::ItemList.push_back(Items::RawQuartz);
				} {
					Items::Sulfur = new Item;
					Items::Sulfur->Name = "Sulfur";
					Items::Sulfur->Description.push_back("Sulfur is primarily used for Black Powder.");
					Items::Sulfur->Category = ItemCategory::Ores;
					Items::Sulfur->MaxStackSize = 100;
					Items::Sulfur->SinkPoint = 11;
					Satisfactory::ItemList.push_back(Items::Sulfur);
				} {
					Items::Bauxite = new Item;
					Items::Bauxite->Name = "Bauxite";
					Items::Bauxite->Description.push_back("Bauxite is used to produce Alumina,");
					Items::Bauxite->Description.push_back("which can be further refined into the Aluminum Scrap required to produce Aluminum Ingots");
					Items::Bauxite->Category = ItemCategory::Ores;
					Items::Bauxite->MaxStackSize = 100;
					Items::Bauxite->SinkPoint = 8;
					Satisfactory::ItemList.push_back(Items::Bauxite);
				} {
					Items::SAMOre = new Item;
					Items::SAMOre->Name = "S.A.M. Ore";
					Items::SAMOre->Description.push_back("Stange Alien Metal that glistens with new possibilities.");
					Items::SAMOre->Category = ItemCategory::Ores;
					Items::SAMOre->MaxStackSize = 50;
					Items::SAMOre->SinkPoint = 0;
					Satisfactory::ItemList.push_back(Items::SAMOre);
				} {
					Items::Uranium = new Item;
					Items::Uranium->Name = "Uranium";
					Items::Uranium->Description.push_back("Uranium is a radioactive element.");
					Items::Uranium->Description.push_back("Used to produce Encased Uranium Cells for Uranium Fuel Rods.");
					Items::Uranium->Radioactive = "Morderately";
					Items::Uranium->Category = ItemCategory::Ores;
					Items::Uranium->MaxStackSize = 100;
					Items::Uranium->SinkPoint = 35;
					Satisfactory::ItemList.push_back(Items::Uranium);
				}

				{ //==============================================================================================| Ingots
					Items::IronIngot = new Item;
					Items::IronIngot->Name = "Iron Ingot";
					Items::IronIngot->Description.push_back("Used for crafting.");
					Items::IronIngot->Description.push_back("Crafted into the most basic parts.");
					Items::IronIngot->Category = ItemCategory::Ingots;
					Items::IronIngot->MaxStackSize = 100;
					Items::IronIngot->SinkPoint = 2;
					Satisfactory::ItemList.push_back(Items::IronIngot);
				} {
					Items::CopperIngot = new Item;
					Items::CopperIngot->Name = "Copper Ingot";
					Items::CopperIngot->Description.push_back("Used for crafting.");
					Items::CopperIngot->Description.push_back("Crafted into the most basic parts.");
					Items::CopperIngot->Category = ItemCategory::Ingots;
					Items::CopperIngot->MaxStackSize = 100;
					Items::CopperIngot->SinkPoint = 6;
					Satisfactory::ItemList.push_back(Items::CopperIngot);
				} {
					Items::CateriumIngot = new Item;
					Items::CateriumIngot->Name = "Caterium Ingot";
					Items::CateriumIngot->Description.push_back("Caterium Ingots are smelted from Caterium Ore.");
					Items::CateriumIngot->Description.push_back("Caterium Ingots are mostly used for advanced electronics.");
					Items::CateriumIngot->Category = ItemCategory::Ingots;
					Items::CateriumIngot->MaxStackSize = 100;
					Items::CateriumIngot->SinkPoint = 42;
					Satisfactory::ItemList.push_back(Items::CateriumIngot);
				} {
					Items::SteelIngot = new Item;
					Items::SteelIngot->Name = "Steel Ingot";
					Items::SteelIngot->Description.push_back("Steel Ingots are made from Iron Ore that's been smelted with Coal.");
					Items::SteelIngot->Description.push_back("They are made into several parts used in building construction.");
					Items::SteelIngot->Category = ItemCategory::Ingots;
					Items::SteelIngot->MaxStackSize = 100;
					Items::SteelIngot->SinkPoint = 8;
					Satisfactory::ItemList.push_back(Items::SteelIngot);
				} {
					Items::AluminumIngot = new Item;
					Items::AluminumIngot->Name = "Aluminum Ingot";
					Items::AluminumIngot->Description.push_back("Aluminum Ingots are made from Aluminum Scrap, which is refined from Alumina Solution.");
					Items::AluminumIngot->Description.push_back("Used to produce specialized aluminum-based parts.");
					Items::AluminumIngot->Category = ItemCategory::Ingots;
					Items::AluminumIngot->MaxStackSize = 100;
					Items::AluminumIngot->SinkPoint = 131;
					Satisfactory::ItemList.push_back(Items::AluminumIngot);
				}
			}

			{
				{ //==============================================================================================| Production
					Buildings::Smelter = new Building;
					Buildings::Smelter->Category = BuildingCategory::Production;
					Buildings::Smelter->PowerUsed = 4;
					Buildings::Smelter->Width = 6;
					Buildings::Smelter->Length = 9;
					Buildings::Smelter->Height = 10;
					Buildings::Smelter->Input = 1;
					Buildings::Smelter->Output = 1;
					Buildings::Smelter->Ingredients.emplace_back(Items::IronRod, 5);
					Buildings::Smelter->Ingredients.emplace_back(Items::Wire, 8);
					Satisfactory::BuildingList.push_back(Buildings::Smelter);

				}
			}

			{

				//==============================================================================================| Ores

				{
					Recipes::IronOre = new Recipe;
					Recipes::IronOre->Name = "Iron Ore";
					Recipes::IronOre->Building = Buildings::MinerMk1;
					Recipes::IronOre->AddOutput(Items::IronOre, 60, 1);
					Satisfactory::RecipeList.push_back(Recipes::IronOre);
				}

				//==============================================================================================| Ingots
				{
					Recipes::IronIngot = new Recipe;
					Recipes::IronIngot->Name = "Iron Ingot";
					Recipes::IronIngot->Building = Buildings::Smelter;
					Recipes::IronIngot->AddInput(Items::IronOre, 30., 1);
					Recipes::IronIngot->AddOutput(Items::IronIngot, 30., 1);
					Satisfactory::RecipeList.push_back(Recipes::IronIngot);
				} {
					Recipes::IronAlloyIngot = new Recipe;
					Recipes::IronAlloyIngot->Name = "Iron Alloy Ingot";
					Recipes::IronAlloyIngot->Building = Buildings::Foundry;
					Recipes::IronAlloyIngot->IsAlt = true;
					Recipes::IronAlloyIngot->AddInput(Items::IronOre, 20., 2);
					Recipes::IronAlloyIngot->AddInput(Items::CopperOre, 20., 2);
					Recipes::IronAlloyIngot->AddOutput(Items::IronIngot, 50., 5);
					Satisfactory::RecipeList.push_back(Recipes::IronAlloyIngot);
				} {
					Recipes::PureIronIngot = new Recipe;
					Recipes::PureIronIngot->Name = "Pure Iron Ingot";
					Recipes::PureIronIngot->Building = Buildings::Refinery;
					Recipes::PureIronIngot->IsAlt = true;
					Recipes::PureIronIngot->AddInput(Items::IronOre, 35., 7);
					Recipes::PureIronIngot->AddInput(Items::Water, 20., 4);
					Recipes::PureIronIngot->AddOutput(Items::IronIngot, 65., 13);
					Satisfactory::RecipeList.push_back(Recipes::PureIronIngot);
				}
			}
		}
	}
}
