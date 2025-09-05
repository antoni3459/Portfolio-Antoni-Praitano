using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class ChangeTeam : MonoBehaviour
{
    [SerializeField] Button button = null;
    [SerializeField] TMP_Text text = null;
	[SerializeField] ColorBlock disableColor;
	[SerializeField] ColorBlock initColor;

	Mob mobRef = null;
	bool canClick = true;


	public Mob MobRef => mobRef;
	public string NameMob => mobRef.NameMob;

	public Button ButtonRef => button;

	private void Start()
	{
		initColor = button.colors;
	}

	public void Init(string _nameMob, Mob _mobRef, Action _event)
    {
		text.text = _nameMob;
		mobRef = _mobRef;
        button.onClick.AddListener(() => Click(_event));
	}

	void Click(Action _event)
	{
		if(!canClick) 
			return;
		_event?.Invoke();
	}

	public void CanEnableButton(bool _enabled)
	{
		canClick = _enabled;
		button.colors = _enabled ? initColor : disableColor;
	}
}
