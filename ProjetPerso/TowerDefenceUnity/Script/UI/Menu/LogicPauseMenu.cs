using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class LogicPauseMenu : LogicMenu
{
	[SerializeField] Button resumeButton = null;
	[SerializeField] Button optionButton = null;
	[SerializeField] Button quitButton = null;

	protected override void Awake()
	{
		base.Awake();

		resumeButton.onClick.AddListener(ResumeButton);
		optionButton.onClick.AddListener(OptionButton);
		quitButton.onClick.AddListener(QuitButton);
	}

	private void Start()
	{
		switchPanel = hud.AllSwitchPanel[typeMenu];
	}
	private void ResumeButton()
	{
		switchPanel.SetNewPanel(0);
	}

	private void OptionButton()
	{
		switchPanel.SetNewPanel(2);
	}

	private void QuitButton()
	{
		StartCoroutine(LoadSceneMainMenu());
	}

	IEnumerator LoadSceneMainMenu()
	{
		AsyncOperation _operation = SceneManager.LoadSceneAsync(0);
		yield return _operation;
	}
}
