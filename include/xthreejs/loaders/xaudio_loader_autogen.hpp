#ifndef XTHREE_AUDIO_LOADER_HPP
#define XTHREE_AUDIO_LOADER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // audio_loader declaration
    //

    template<class D>
    class xaudio_loader : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xaudio_loader();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using audio_loader = xw::xmaterialize<xaudio_loader>;

    using audio_loader_generator = xw::xgenerator<xaudio_loader>;

    //
    // audio_loader implementation
    //


    template <class D>
    inline void xaudio_loader<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xaudio_loader<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xaudio_loader<D>::xaudio_loader()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xaudio_loader<D>::set_defaults()
    {
        this->_model_name() = "AudioLoaderModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xaudio_loader));
//}
#endif