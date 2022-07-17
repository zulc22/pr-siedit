#ifndef WAVPANEL_H
#define WAVPANEL_H

#include <othertypes.h>
#include <QAudioOutput>
#include <QBuffer>
#include <QByteArray>
#include <QPushButton>
#include <QSlider>
#include <QTimer>

#include "panel.h"

class WavPanel : public Panel
{
  Q_OBJECT
public:
  WavPanel(QWidget *parent = nullptr);

protected:
  virtual void OnOpeningData(void *data) override;
  virtual void OnClosingData(void *data) override;

private:
  int GetSampleSize() const;

  QSlider *playhead_slider_;
  QPushButton *play_btn_;

  QAudioOutput *audio_out_;
  QBuffer buffer_;
  QByteArray array_;
  QTimer *playback_timer_;
  si::WAVFmt header_;
  QByteArray play_buffer_;

private slots:
  void Play(bool e);

  void TimerUpdate();

  void OutputChanged(QAudio::State state);

  void SliderMoved(int i);

};

#endif // WAVPANEL_H
