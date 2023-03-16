/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:06:18 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/16 14:57:15 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/raycast_bonus.h"

pthread_mutex_t	g_buffer_mutex;

void	ft_start_shoot_thread(void)
{
	pthread_t	thread;

	pthread_mutex_init(&g_buffer_mutex, NULL);
	pthread_create(&thread, NULL, ft_shoot_sound, NULL);
	pthread_detach(thread);
	pthread_mutex_destroy(&g_buffer_mutex);
}

void	*ft_shoot_sound(void)
{
	SDL_AudioSpec		wav_spec;
	Uint8				*wav_buffer;
	Uint32				wav_length;
	SDL_AudioDeviceID	device_id;

	pthread_mutex_lock(&g_buffer_mutex);
	SDL_Init(SDL_INIT_AUDIO);
	SDL_LoadWAV("./sounds/gunshot.wav", &wav_spec, &wav_buffer, &wav_length);
	device_id = SDL_OpenAudioDevice(NULL, 0, &wav_spec, NULL, 0);
	SDL_QueueAudio(device_id, wav_buffer, wav_length);
	SDL_PauseAudioDevice(device_id, 0);
	SDL_Delay(1000);
	SDL_FreeWAV(wav_buffer);
	SDL_CloseAudioDevice(device_id);
	SDL_Quit();
	pthread_mutex_unlock(&g_buffer_mutex);
	return (NULL);
}
