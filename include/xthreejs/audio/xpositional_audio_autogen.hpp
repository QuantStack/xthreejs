#ifndef XTHREE_POSITIONAL_AUDIO_HPP
#define XTHREE_POSITIONAL_AUDIO_HPP

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
    // positional_audio declaration
    //

    template<class D>
    class xpositional_audio : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xpositional_audio();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using positional_audio = xw::xmaterialize<xpositional_audio>;

    using positional_audio_generator = xw::xgenerator<xpositional_audio>;

    //
    // positional_audio implementation
    //


    template <class D>
    inline void xpositional_audio<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xpositional_audio<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xpositional_audio<D>::xpositional_audio()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xpositional_audio<D>::set_defaults()
    {
        this->_model_name() = "PositionalAudioModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xpositional_audio>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xpositional_audio>>;
    extern template class xw::xgenerator<xthree::xpositional_audio>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xpositional_audio>>;
#endif

#endif