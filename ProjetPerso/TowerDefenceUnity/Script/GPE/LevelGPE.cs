using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LevelGPE : MonoBehaviour
{
    bool isUnblock = false;
    int indexLevel = 0;

	private void Awake()
	{
		ManagerLevel.Instance.AddLevelGPE(this);
	}
	void Start()
    {
        
    }

    void Update()
    {
        
    }
}
