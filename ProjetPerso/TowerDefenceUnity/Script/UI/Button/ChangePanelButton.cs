using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ChangePanelButton : MonoBehaviour
{
    [SerializeField] Button button = null;
    [SerializeField] int newPanelIndex = 0;
    [SerializeField] ETYPE_MENU typeMenu = ETYPE_MENU.DEFAULT;

	SwitchPanel switchPanele = null;

	private void Awake()
	{
        button.onClick.AddListener(ChangePanel);
		switchPanele = HUD.Instance.AllSwitchPanel[typeMenu];
	}
	void Start()
    {
        
    }

    void ChangePanel()
    {
        switchPanele.SetNewPanel(newPanelIndex);
	}
}
