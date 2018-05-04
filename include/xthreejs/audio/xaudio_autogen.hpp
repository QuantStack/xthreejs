#ifndef XTHREE_AUDIO_HPP
#define XTHREE_AUDIO_HPP

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
    // audio declaration
    //

    template<class D>
    class xaudio : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xaudio();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using audio = xw::xmaterialize<xaudio>;

    using audio_generator = xw::xgenerator<xaudio>;

    //
    // audio implementation
    //


    template <class D>
    inline void xaudio<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xaudio<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xaudio<D>::xaudio()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xaudio<D>::set_defaults()
    {
        this->_model_name() = "AudioModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xaudio));
//}
#endif