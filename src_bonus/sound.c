/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:06:18 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/15 12:24:34 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/raycast_bonus.h"
pthread_mutex_t buffer_mutex;

void	ft_start_shoot_thread(void)
{
	pthread_t	thread;

	pthread_mutex_init(&buffer_mutex, NULL);
	pthread_create(&thread, NULL, ft_shoot_sound, NULL);
	pthread_detach(thread);
	pthread_mutex_destroy(&buffer_mutex);
}

void	*ft_shoot_sound()
{
	SDL_AudioSpec		wavSpec;
	Uint8				*wavBuffer;
	Uint32				wavLength;
	SDL_AudioDeviceID	deviceId;

	pthread_mutex_lock(&buffer_mutex);
	SDL_Init(SDL_INIT_AUDIO);
	SDL_LoadWAV("./sounds/gunshot.wav", &wavSpec, &wavBuffer, &wavLength);
	deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
	SDL_QueueAudio(deviceId, wavBuffer, wavLength);
	SDL_PauseAudioDevice(deviceId, 0);
	SDL_Delay(1000);
	SDL_FreeWAV(wavBuffer);
	SDL_CloseAudioDevice(deviceId);
	SDL_Quit();
	pthread_mutex_unlock(&buffer_mutex);
	return (NULL);
}
