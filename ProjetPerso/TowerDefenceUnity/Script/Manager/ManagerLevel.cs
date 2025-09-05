using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ManagerLevel : Singleton<ManagerLevel>
{
	List<LevelGPE> allLevelGPE;

	public void AddLevelGPE(LevelGPE _levelGPE)
	{
		allLevelGPE.Add(_levelGPE);
	}
}
