using System.Collections;
using System.Collections.Generic;
using UnityEngine;


[CreateAssetMenu(fileName = "Stat Panel", menuName = "UI/Stat Panel")]
public class ScriptablePanel : ScriptableObject
{
	[SerializeField] List<GameObject> allPanel;

	public List<GameObject> AllPanel => allPanel;
	public GameObject Panel(int _index) => allPanel[_index];
}
