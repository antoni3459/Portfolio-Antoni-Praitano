using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SwitchPanel : MonoBehaviour
{
	[SerializeField] ScriptablePanel panel = null;
	[SerializeField] Transform parent = null;
	[SerializeField] ETYPE_MENU typeMenu = ETYPE_MENU.DEFAULT;

	GameObject currentPanel = null;

	int indexPanel;
	private void Awake()
	{
	}
	private void Start()
	{
		HUD.Instance.AddSwitchPanel(typeMenu, this);

		currentPanel = Instantiate(panel.Panel(indexPanel), parent.transform);
	}
	public void SetNewPanel(int _index)
	{
		Destroy(currentPanel);
		currentPanel = Instantiate(panel.Panel(_index), parent.transform);
		indexPanel = _index;
	}
}
