#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xaudio_listener>;
template xw::xmaterialize<xthree::xaudio_listener>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xaudio_listener>>;
template class xw::xgenerator<xthree::xaudio_listener>;
template xw::xgenerator<xthree::xaudio_listener>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xaudio_listener>>;